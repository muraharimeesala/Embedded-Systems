/*
================================================================================
SIGNAL HANDLING EXAMPLES
================================================================================
Compile: gcc -o signal_examples signal_examples.c
Run: ./signal_examples
================================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

// Global flag for signal handling
volatile sig_atomic_t signal_received = 0;
volatile sig_atomic_t signal_count = 0;
volatile sig_atomic_t child_exited = 0;

/*
================================================================================
EXAMPLE 1: Basic Signal Handler with signal()
================================================================================
*/
void example1_handler(int sig) {
    printf("[EXAMPLE 1] Signal %d received!\n", sig);
    signal_received = 1;
}

void example1_basic_signal() {
    printf("\n=== EXAMPLE 1: Basic Signal Handler ===\n");
    printf("Press Ctrl+C to send SIGINT (or wait 3 seconds)...\n");
    
    signal(SIGINT, example1_handler);
    
    for (int i = 0; i < 3; i++) {
        printf("Waiting... (%d/3)\n", i + 1);
        sleep(1);
        if (signal_received) break;
    }
    
    if (signal_received) {
        printf("Signal was received!\n");
    } else {
        printf("No signal received.\n");
    }
}

/*
================================================================================
EXAMPLE 2: Signal Handler with sigaction()
================================================================================
*/
void example2_handler(int sig, siginfo_t *info, void *context) {
    printf("[EXAMPLE 2] Signal %d from PID %d (UID: %d)\n", 
           sig, info->si_pid, info->si_uid);
    signal_count++;
}

void example2_sigaction() {
    printf("\n=== EXAMPLE 2: sigaction() Handler ===\n");
    printf("Press Ctrl+C multiple times (or wait 5 seconds)...\n");
    
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = example2_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    
    sigaction(SIGINT, &sa, NULL);
    
    for (int i = 0; i < 5; i++) {
        printf("Waiting... (%d/5) - Signals received: %d\n", i + 1, signal_count);
        sleep(1);
    }
    
    printf("Total signals received: %d\n", signal_count);
}

/*
================================================================================
EXAMPLE 3: Ignoring Signals
================================================================================
*/
void example3_ignore_signal() {
    printf("\n=== EXAMPLE 3: Ignoring Signals ===\n");
    printf("SIGINT is now ignored. Press Ctrl+C multiple times (5 seconds)...\n");
    
    signal(SIGINT, SIG_IGN);
    
    for (int i = 0; i < 5; i++) {
        printf("Still running... (%d/5)\n", i + 1);
        sleep(1);
    }
    
    printf("SIGINT was ignored successfully!\n");
}

/*
================================================================================
EXAMPLE 4: Blocking and Unblocking Signals
================================================================================
*/
void example4_block_unblock() {
    printf("\n=== EXAMPLE 4: Blocking Signals ===\n");
    
    sigset_t set, oldset;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    
    // Block SIGINT
    sigprocmask(SIG_BLOCK, &set, &oldset);
    printf("SIGINT is BLOCKED. Try Ctrl+C for 3 seconds...\n");
    for (int i = 0; i < 3; i++) {
        printf("  %d...\n", i + 1);
        sleep(1);
    }
    
    // Unblock SIGINT
    sigprocmask(SIG_UNBLOCK, &set, NULL);
    printf("SIGINT is now UNBLOCKED. Try Ctrl+C in next 3 seconds...\n");
    
    signal(SIGINT, example1_handler);
    signal_received = 0;
    
    for (int i = 0; i < 3; i++) {
        printf("  %d...\n", i + 1);
        sleep(1);
        if (signal_received) {
            printf("Signal received while unblocked!\n");
            break;
        }
    }
}

/*
================================================================================
EXAMPLE 5: Signal Mask Query
================================================================================
*/
void example5_query_mask() {
    printf("\n=== EXAMPLE 5: Query Signal Mask ===\n");
    
    sigset_t set;
    sigprocmask(SIG_SETMASK, NULL, &set);
    
    printf("Checking blocked signals:\n");
    if (sigismember(&set, SIGINT)) {
        printf("  - SIGINT is BLOCKED\n");
    } else {
        printf("  - SIGINT is NOT blocked\n");
    }
    
    if (sigismember(&set, SIGTERM)) {
        printf("  - SIGTERM is BLOCKED\n");
    } else {
        printf("  - SIGTERM is NOT blocked\n");
    }
}

/*
================================================================================
EXAMPLE 6: Multiple Signal Handlers
================================================================================
*/
void sigint_handler(int sig) {
    signal_count++;
    printf("\n[SIGINT] Count: %d\n", signal_count);
}

void sigalrm_handler(int sig) {
    printf("[SIGALRM] Timer expired!\n");
}

void example6_multiple_handlers() {
    printf("\n=== EXAMPLE 6: Multiple Signal Handlers ===\n");
    printf("SIGINT: Ctrl+C (increments counter)\n");
    printf("SIGALRM: Automatically sent after 3 seconds\n");
    
    signal(SIGINT, sigint_handler);
    signal(SIGALRM, sigalrm_handler);
    
    alarm(3);  // Send SIGALRM after 3 seconds
    
    printf("Waiting 5 seconds...\n");
    for (int i = 0; i < 5; i++) {
        printf("  %d...\n", i + 1);
        sleep(1);
    }
    
    printf("Total SIGINT count: %d\n", signal_count);
}

/*
================================================================================
EXAMPLE 7: Using pause()
================================================================================
*/
void example7_pause() {
    printf("\n=== EXAMPLE 7: Using pause() ===\n");
    printf("Press Ctrl+C to continue (or wait for SIGALRM after 3 seconds)...\n");
    
    signal_received = 0;
    signal(SIGINT, example1_handler);
    signal(SIGALRM, example1_handler);
    
    alarm(3);
    
    printf("Calling pause()...\n");
    pause();  // Wait for any signal
    
    printf("pause() returned. Signal was caught.\n");
    printf("Signal received flag: %d\n", signal_received);
}

/*
================================================================================
EXAMPLE 8: Parent-Child Process with SIGCHLD
================================================================================
*/
void sigchld_handler(int sig) {
    int status;
    pid_t pid = waitpid(-1, &status, 0);
    child_exited = 1;
    
    if (WIFEXITED(status)) {
        printf("[PARENT] Child %d exited with status %d\n", 
               pid, WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("[PARENT] Child %d killed by signal %d\n", 
               pid, WTERMSIG(status));
    }
}

void example8_parent_child() {
    printf("\n=== EXAMPLE 8: Parent-Child with SIGCHLD ===\n");
    
    signal(SIGCHLD, sigchld_handler);
    
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        printf("[CHILD] Starting (PID: %d)\n", getpid());
        for (int i = 0; i < 3; i++) {
            printf("[CHILD] Working... (%d/3)\n", i + 1);
            sleep(1);
        }
        printf("[CHILD] Exiting with status 42\n");
        exit(42);
    } else if (pid > 0) {
        // Parent process
        printf("[PARENT] Child started with PID: %d\n", pid);
        printf("[PARENT] Waiting for child...\n");
        
        for (int i = 0; i < 5; i++) {
            printf("[PARENT] Main loop... (%d/5)\n", i + 1);
            sleep(1);
            if (child_exited) {
                printf("[PARENT] Child exited!\n");
                break;
            }
        }
    }
}

/*
================================================================================
EXAMPLE 9: Signal Mask with sigsuspend()
================================================================================
*/
volatile sig_atomic_t sigusr1_received = 0;

void sigusr1_handler(int sig) {
    sigusr1_received = 1;
    printf("[SIGUSR1] Signal received\n");
}

void example9_sigsuspend() {
    printf("\n=== EXAMPLE 9: sigsuspend() ===\n");
    printf("This would normally receive a signal from another process.\n");
    printf("For demo, press Ctrl+C after 2 seconds to simulate.\n");
    
    sigset_t newset, oldset;
    
    signal(SIGINT, sigint_handler);
    signal(SIGUSR1, sigusr1_handler);
    
    sigemptyset(&newset);
    sigaddset(&newset, SIGUSR1);
    
    // Block SIGUSR1, save old mask
    sigprocmask(SIG_BLOCK, &newset, &oldset);
    
    printf("SIGUSR1 is blocked. Calling sigsuspend()...\n");
    printf("(In practice, another process would send SIGUSR1)\n");
    
    alarm(2);
    
    // Temporarily restore old mask and wait
    sigsuspend(&oldset);
    
    printf("sigsuspend() returned\n");
}

/*
================================================================================
EXAMPLE 10: Reliable Signal Handling with volatile sig_atomic_t
================================================================================
*/
volatile sig_atomic_t counter = 0;

void counter_handler(int sig) {
    counter++;  // Safe with sig_atomic_t
}

void example10_reliable_handling() {
    printf("\n=== EXAMPLE 10: Reliable Signal Handling ===\n");
    printf("Press Ctrl+C multiple times rapidly to increment counter...\n");
    
    signal(SIGINT, counter_handler);
    
    printf("Starting...\n");
    for (int i = 0; i < 5; i++) {
        printf("Counter: %d\n", counter);
        sleep(1);
    }
    
    printf("Final counter value: %d\n", counter);
}

/*
================================================================================
EXAMPLE 11: Sending Signals Between Processes
================================================================================
*/
void example11_send_signal() {
    printf("\n=== EXAMPLE 11: Sending Signals ===\n");
    
    signal(SIGUSR1, sigusr1_handler);
    sigusr1_received = 0;
    
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child sends signal to parent
        printf("[CHILD] Sleeping 2 seconds...\n");
        sleep(2);
        printf("[CHILD] Sending SIGUSR1 to parent (PID %d)\n", getppid());
        kill(getppid(), SIGUSR1);
        printf("[CHILD] Exiting\n");
        exit(0);
    } else {
        // Parent receives signal
        printf("[PARENT] Waiting to receive SIGUSR1...\n");
        for (int i = 0; i < 5; i++) {
            printf("[PARENT] Waiting... (%d/5)\n", i + 1);
            sleep(1);
            if (sigusr1_received) {
                printf("[PARENT] Signal received!\n");
                break;
            }
        }
        wait(NULL);
    }
}

/*
================================================================================
EXAMPLE 12: Signal Mask Manipulation
================================================================================
*/
void example12_mask_manipulation() {
    printf("\n=== EXAMPLE 12: Signal Mask Manipulation ===\n");
    
    sigset_t set;
    
    // Fill with all signals, then remove some
    sigfillset(&set);
    sigdelset(&set, SIGINT);
    sigdelset(&set, SIGTERM);
    
    printf("Blocking all signals except SIGINT and SIGTERM\n");
    sigprocmask(SIG_BLOCK, &set, NULL);
    
    // Check which signals are blocked
    sigprocmask(SIG_SETMASK, NULL, &set);
    
    printf("Signal mask status:\n");
    if (sigismember(&set, SIGINT)) {
        printf("  - SIGINT: BLOCKED\n");
    } else {
        printf("  - SIGINT: NOT blocked\n");
    }
    
    if (sigismember(&set, SIGTERM)) {
        printf("  - SIGTERM: BLOCKED\n");
    } else {
        printf("  - SIGTERM: NOT blocked\n");
    }
    
    if (sigismember(&set, SIGALRM)) {
        printf("  - SIGALRM: BLOCKED\n");
    } else {
        printf("  - SIGALRM: NOT blocked\n");
    }
}

/*
================================================================================
MAIN MENU
================================================================================
*/
int main() {
    int choice = -1;
    
    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║   SIGNAL HANDLING EXAMPLES FOR LINUX       ║\n");
    printf("║   Embedded Software Development Training   ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("\nSelect an example to run:\n\n");
    printf("  1. Basic Signal Handler (signal())\n");
    printf("  2. Advanced Handler (sigaction())\n");
    printf("  3. Ignoring Signals\n");
    printf("  4. Blocking/Unblocking Signals\n");
    printf("  5. Query Signal Mask\n");
    printf("  6. Multiple Signal Handlers\n");
    printf("  7. Using pause()\n");
    printf("  8. Parent-Child with SIGCHLD\n");
    printf("  9. Using sigsuspend()\n");
    printf(" 10. Reliable Signal Handling\n");
    printf(" 11. Sending Signals Between Processes\n");
    printf(" 12. Signal Mask Manipulation\n");
    printf("  0. Exit\n\n");
    
    printf("Enter choice (0-12): ");
    scanf("%d", &choice);
    
    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    printf("\n");
    
    switch(choice) {
        case 1:
            example1_basic_signal();
            break;
        case 2:
            signal_count = 0;
            example2_sigaction();
            break;
        case 3:
            example3_ignore_signal();
            break;
        case 4:
            example4_block_unblock();
            break;
        case 5:
            example5_query_mask();
            break;
        case 6:
            signal_count = 0;
            example6_multiple_handlers();
            break;
        case 7:
            example7_pause();
            break;
        case 8:
            example8_parent_child();
            break;
        case 9:
            example9_sigsuspend();
            break;
        case 10:
            counter = 0;
            example10_reliable_handling();
            break;
        case 11:
            example11_send_signal();
            break;
        case 12:
            example12_mask_manipulation();
            break;
        case 0:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
    }
    
    printf("\n");
    return 0;
}
