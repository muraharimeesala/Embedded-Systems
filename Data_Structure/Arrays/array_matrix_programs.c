/*
 * ============================================================
 *  26 Array & Matrix Programs in C
 *  Optimized for Time & Space Complexity
 * ============================================================
 */

#include <stdio.h>
#include <limits.h>   /* INT_MIN, INT_MAX */

/* ─────────────────────────────────────────────
   HELPER MACROS
   ───────────────────────────────────────────── */
#define SWAP(a, b) do { int t = (a); (a) = (b); (b) = t; } while (0)
#define N  5          /* default 1-D array size   */
#define R  3          /* default matrix rows/cols  */

/* ============================================================
   1. Store elements in an array and print them
   Time: O(n)  |  Space: O(n)
   ============================================================ */
void prog01(void)
{
    int arr[N], i;
    printf("\n--- 1. Store & Print Array ---\n");
    printf("Enter %d elements: ", N);
    for (i = 0; i < N; i++) scanf("%d", &arr[i]);

    printf("Array: ");
    for (i = 0; i < N; i++) printf("%d ", arr[i]);
    printf("\n");
}

/* ============================================================
   2. Read n values and display in reverse order
   Time: O(n)  |  Space: O(n)  – single pass store, reverse print
   ============================================================ */
void prog02(void)
{
    int n, i;
    printf("\n--- 2. Reverse Order ---\n");
    printf("Enter n: "); scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Reversed: ");
    for (i = n - 1; i >= 0; i--) printf("%d ", arr[i]);
    printf("\n");
}

/* ============================================================
   3. Sum of all elements
   Time: O(n)  |  Space: O(1) extra
   ============================================================ */
void prog03(void)
{
    int arr[N], i, sum = 0;
    printf("\n--- 3. Sum of Elements ---\n");
    printf("Enter %d elements: ", N);
    for (i = 0; i < N; i++) { scanf("%d", &arr[i]); sum += arr[i]; }

    printf("Sum = %d\n", sum);
}

/* ============================================================
   4. Copy one array into another
   Time: O(n)  |  Space: O(n) for destination
   ============================================================ */
void prog04(void)
{
    int src[N], dest[N], i;
    printf("\n--- 4. Copy Array ---\n");
    printf("Enter %d elements: ", N);
    for (i = 0; i < N; i++) { scanf("%d", &src[i]); dest[i] = src[i]; }

    printf("Copied array: ");
    for (i = 0; i < N; i++) printf("%d ", dest[i]);
    printf("\n");
}

/* ============================================================
   5. Count duplicate elements
   Time: O(n²)  |  Space: O(1) extra
   – marks counted duplicates to avoid re-counting
   ============================================================ */
void prog05(void)
{
    int arr[N], i, j, count = 0;
    printf("\n--- 5. Count Duplicates ---\n");
    printf("Enter %d elements: ", N);
    for (i = 0; i < N; i++) scanf("%d", &arr[i]);

    for (i = 0; i < N - 1; i++) {
        int found = 0;
        for (j = i + 1; j < N; j++) {
            if (arr[i] == arr[j]) { found = 1; arr[j] = INT_MIN; }
        }
        if (found) { count++; arr[i] = INT_MIN; }
    }
    printf("Total duplicate elements: %d\n", count);
}

/* ============================================================
   6. Print all unique elements
   Time: O(n²)  |  Space: O(1) extra
   ============================================================ */
void prog06(void)
{
    int arr[N], i, j;
    printf("\n--- 6. Unique Elements ---\n");
    printf("Enter %d elements: ", N);
    for (i = 0; i < N; i++) scanf("%d", &arr[i]);

    printf("Unique elements: ");
    for (i = 0; i < N; i++) {
        int unique = 1;
        for (j = 0; j < N; j++)
            if (i != j && arr[i] == arr[j]) { unique = 0; break; }
        if (unique) printf("%d ", arr[i]);
    }
    printf("\n");
}

/* ============================================================
   7. Merge two arrays of same size → sorted descending
   Time: O(n log n)  |  Space: O(2n) for merged array
   – uses insertion sort (good for small n)
   ============================================================ */
void prog07(void)
{
    int a[N], b[N], merged[2 * N], i, j, key;
    printf("\n--- 7. Merge & Sort Descending ---\n");
    printf("Array 1 (%d elements): ", N);
    for (i = 0; i < N; i++) scanf("%d", &a[i]);
    printf("Array 2 (%d elements): ", N);
    for (i = 0; i < N; i++) scanf("%d", &b[i]);

    /* combine */
    for (i = 0; i < N; i++)      merged[i]     = a[i];
    for (i = 0; i < N; i++)      merged[N + i] = b[i];

    /* insertion sort – descending */
    for (i = 1; i < 2 * N; i++) {
        key = merged[i];
        for (j = i - 1; j >= 0 && merged[j] < key; j--)
            merged[j + 1] = merged[j];
        merged[j + 1] = key;
    }
    printf("Merged (desc): ");
    for (i = 0; i < 2 * N; i++) printf("%d ", merged[i]);
    printf("\n");
}

/* ============================================================
   8. Frequency of each element
   Time: O(n²)  |  Space: O(n) visited flag
   ============================================================ */
void prog08(void)
{
    int arr[N], visited[N], i, j, freq;
    printf("\n--- 8. Frequency Count ---\n");
    printf("Enter %d elements: ", N);
    for (i = 0; i < N; i++) { scanf("%d", &arr[i]); visited[i] = 0; }

    for (i = 0; i < N; i++) {
        if (visited[i]) continue;
        freq = 1;
        for (j = i + 1; j < N; j++)
            if (arr[i] == arr[j]) { freq++; visited[j] = 1; }
        printf("%d appears %d time(s)\n", arr[i], freq);
    }
}

/* ============================================================
   9. Maximum and minimum element
   Time: O(n)  |  Space: O(1) extra
   ============================================================ */
void prog09(void)
{
    int arr[N], i, max, min;
    printf("\n--- 9. Max & Min ---\n");
    printf("Enter %d elements: ", N);
    scanf("%d", &arr[0]); max = min = arr[0];
    for (i = 1; i < N; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("Max = %d, Min = %d\n", max, min);
}

/* ============================================================
   10. Separate odd and even integers
   Time: O(n)  |  Space: O(n) for two output arrays
   ============================================================ */
void prog10(void)
{
    int arr[N], odd[N], even[N], oc = 0, ec = 0, i;
    printf("\n--- 10. Odd & Even Separation ---\n");
    printf("Enter %d elements: ", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 != 0) odd[oc++]  = arr[i];
        else                  even[ec++] = arr[i];
    }
    printf("Even: "); for (i = 0; i < ec; i++) printf("%d ", even[i]); printf("\n");
    printf("Odd : "); for (i = 0; i < oc; i++) printf("%d ", odd[i]);  printf("\n");
}

/* ============================================================
   11. Sort in ascending order  (Insertion Sort)
   Time: O(n²) worst | O(n) best  |  Space: O(1)
   ============================================================ */
void prog11(void)
{
    int arr[N], i, j, key;
    printf("\n--- 11. Sort Ascending ---\n");
    printf("Enter %d elements: ", N);
    for (i = 0; i < N; i++) scanf("%d", &arr[i]);

    for (i = 1; i < N; i++) {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--) arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
    printf("Ascending: ");
    for (i = 0; i < N; i++) printf("%d ", arr[i]);
    printf("\n");
}

/* ============================================================
   12. Sort in descending order  (Insertion Sort)
   Time: O(n²) worst | O(n) best  |  Space: O(1)
   ============================================================ */
void prog12(void)
{
    int arr[N], i, j, key;
    printf("\n--- 12. Sort Descending ---\n");
    printf("Enter %d elements: ", N);
    for (i = 0; i < N; i++) scanf("%d", &arr[i]);

    for (i = 1; i < N; i++) {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] < key; j--) arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
    printf("Descending: ");
    for (i = 0; i < N; i++) printf("%d ", arr[i]);
    printf("\n");
}

/* ============================================================
   13. Delete element at a desired position
   Time: O(n)  |  Space: O(1) extra  (shift-left in-place)
   ============================================================ */
void prog13(void)
{
    int arr[N], i, pos;
    printf("\n--- 13. Delete at Position ---\n");
    printf("Enter %d elements: ", N);
    for (i = 0; i < N; i++) scanf("%d", &arr[i]);

    printf("Enter position to delete (0 to %d): ", N - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= N) { printf("Invalid position!\n"); return; }

    for (i = pos; i < N - 1; i++) arr[i] = arr[i + 1];  /* shift left */

    printf("After deletion: ");
    for (i = 0; i < N - 1; i++) printf("%d ", arr[i]);
    printf("\n");
}

/* ============================================================
   14. Second largest element
   Time: O(n)  |  Space: O(1) — single pass with two variables
   ============================================================ */
void prog14(void)
{
    int arr[N], i, first, second;
    printf("\n--- 14. Second Largest ---\n");
    printf("Enter %d elements: ", N);
    for (i = 0; i < N; i++) scanf("%d", &arr[i]);

    first = second = INT_MIN;
    for (i = 0; i < N; i++) {
        if (arr[i] > first)        { second = first; first = arr[i]; }
        else if (arr[i] > second && arr[i] != first) second = arr[i];
    }
    if (second == INT_MIN) printf("No second largest (all same)\n");
    else                   printf("Second Largest = %d\n", second);
}

/* ============================================================
   15. Second smallest element
   Time: O(n)  |  Space: O(1) — single pass
   ============================================================ */
void prog15(void)
{
    int arr[N], i, first, second;
    printf("\n--- 15. Second Smallest ---\n");
    printf("Enter %d elements: ", N);
    for (i = 0; i < N; i++) scanf("%d", &arr[i]);

    first = second = INT_MAX;
    for (i = 0; i < N; i++) {
        if (arr[i] < first)         { second = first; first = arr[i]; }
        else if (arr[i] < second && arr[i] != first) second = arr[i];
    }
    if (second == INT_MAX) printf("No second smallest (all same)\n");
    else                   printf("Second Smallest = %d\n", second);
}

/* ────────────────────────────────────────────────────────────
   MATRIX SECTION  (R × R = 3×3 by default)
   ──────────────────────────────────────────────────────────── */

/* helper: read a matrix */
static void read_matrix(int m[R][R], const char *label)
{
    int i, j;
    printf("Enter %s (%dx%d):\n", label, R, R);
    for (i = 0; i < R; i++)
        for (j = 0; j < R; j++) scanf("%d", &m[i][j]);
}

/* helper: print a matrix */
static void print_matrix(int m[R][R])
{
    int i, j;
    for (i = 0; i < R; i++) {
        for (j = 0; j < R; j++) printf("%5d", m[i][j]);
        printf("\n");
    }
}

/* ============================================================
   16. 2D array 3×3 – input and print
   Time: O(n²)  |  Space: O(n²)
   ============================================================ */
void prog16(void)
{
    int m[R][R];
    printf("\n--- 16. 3×3 Matrix ---\n");
    read_matrix(m, "matrix");
    printf("Matrix:\n"); print_matrix(m);
}

/* ============================================================
   17. Add two matrices
   Time: O(n²)  |  Space: O(n²) for result
   ============================================================ */
void prog17(void)
{
    int a[R][R], b[R][R], res[R][R], i, j;
    printf("\n--- 17. Matrix Addition ---\n");
    read_matrix(a, "Matrix A"); read_matrix(b, "Matrix B");
    for (i = 0; i < R; i++)
        for (j = 0; j < R; j++) res[i][j] = a[i][j] + b[i][j];
    printf("A + B:\n"); print_matrix(res);
}

/* ============================================================
   18. Subtract two matrices
   Time: O(n²)  |  Space: O(n²)
   ============================================================ */
void prog18(void)
{
    int a[R][R], b[R][R], res[R][R], i, j;
    printf("\n--- 18. Matrix Subtraction ---\n");
    read_matrix(a, "Matrix A"); read_matrix(b, "Matrix B");
    for (i = 0; i < R; i++)
        for (j = 0; j < R; j++) res[i][j] = a[i][j] - b[i][j];
    printf("A - B:\n"); print_matrix(res);
}

/* ============================================================
   19. Multiply two square matrices
   Time: O(n³)  |  Space: O(n²)
   ============================================================ */
void prog19(void)
{
    int a[R][R], b[R][R], res[R][R], i, j, k;
    printf("\n--- 19. Matrix Multiplication ---\n");
    read_matrix(a, "Matrix A"); read_matrix(b, "Matrix B");
    for (i = 0; i < R; i++)
        for (j = 0; j < R; j++) {
            res[i][j] = 0;
            for (k = 0; k < R; k++) res[i][j] += a[i][k] * b[k][j];
        }
    printf("A × B:\n"); print_matrix(res);
}

/* ============================================================
   20. Transpose of a matrix  (in-place for square matrix)
   Time: O(n²)  |  Space: O(1) extra
   ============================================================ */
void prog20(void)
{
    int m[R][R], i, j;
    printf("\n--- 20. Transpose ---\n");
    read_matrix(m, "matrix");
    for (i = 0; i < R; i++)
        for (j = i + 1; j < R; j++) SWAP(m[i][j], m[j][i]);
    printf("Transpose:\n"); print_matrix(m);
}

/* ============================================================
   21. Sum of RIGHT diagonal  (main diagonal: i == j)
   Time: O(n)  |  Space: O(1)
   ============================================================ */
void prog21(void)
{
    int m[R][R], i, sum = 0;
    printf("\n--- 21. Sum of Right Diagonal ---\n");
    read_matrix(m, "matrix");
    for (i = 0; i < R; i++) sum += m[i][i];
    printf("Sum of right (main) diagonal = %d\n", sum);
}

/* ============================================================
   22. Sum of LEFT diagonal  (anti-diagonal: i + j == R-1)
   Time: O(n)  |  Space: O(1)
   ============================================================ */
void prog22(void)
{
    int m[R][R], i, sum = 0;
    printf("\n--- 22. Sum of Left Diagonal ---\n");
    read_matrix(m, "matrix");
    for (i = 0; i < R; i++) sum += m[i][R - 1 - i];
    printf("Sum of left (anti) diagonal = %d\n", sum);
}

/* ============================================================
   23. Sum of each row and each column
   Time: O(n²)  |  Space: O(n) for row/col sums
   ============================================================ */
void prog23(void)
{
    int m[R][R], i, j, rowSum, colSum;
    printf("\n--- 23. Row & Column Sums ---\n");
    read_matrix(m, "matrix");
    for (i = 0; i < R; i++) {
        rowSum = 0;
        for (j = 0; j < R; j++) rowSum += m[i][j];
        printf("Row %d sum = %d\n", i, rowSum);
    }
    for (j = 0; j < R; j++) {
        colSum = 0;
        for (i = 0; i < R; i++) colSum += m[i][j];
        printf("Col %d sum = %d\n", j, colSum);
    }
}

/* ============================================================
   24. Lower triangular matrix  (print 0 above diagonal)
   Time: O(n²)  |  Space: O(1) extra
   ============================================================ */
void prog24(void)
{
    int m[R][R], i, j;
    printf("\n--- 24. Lower Triangular ---\n");
    read_matrix(m, "matrix");
    printf("Lower Triangular:\n");
    for (i = 0; i < R; i++) {
        for (j = 0; j < R; j++)
            printf("%5d", (j <= i) ? m[i][j] : 0);
        printf("\n");
    }
}

/* ============================================================
   25. Upper triangular matrix  (print 0 below diagonal)
   Time: O(n²)  |  Space: O(1) extra
   ============================================================ */
void prog25(void)
{
    int m[R][R], i, j;
    printf("\n--- 25. Upper Triangular ---\n");
    read_matrix(m, "matrix");
    printf("Upper Triangular:\n");
    for (i = 0; i < R; i++) {
        for (j = 0; j < R; j++)
            printf("%5d", (j >= i) ? m[i][j] : 0);
        printf("\n");
    }
}

/* ============================================================
   26. Determinant of a 3×3 matrix
   Time: O(1) – fixed 3×3 cofactor expansion  |  Space: O(1)
   ============================================================ */
void prog26(void)
{
    int m[R][R];
    long long det;
    printf("\n--- 26. Determinant of 3×3 ---\n");
    read_matrix(m, "matrix");

    det = (long long)m[0][0] * (m[1][1]*m[2][2] - m[1][2]*m[2][1])
        - (long long)m[0][1] * (m[1][0]*m[2][2] - m[1][2]*m[2][0])
        + (long long)m[0][2] * (m[1][0]*m[2][1] - m[1][1]*m[2][0]);

    printf("Determinant = %lld\n", det);
}

/* ============================================================
   MAIN – menu-driven driver
   ============================================================ */
int main(void)
{
    int choice;
    do {
        printf("\n========== MENU ==========\n");
        printf(" 1. Store & Print Array\n");
        printf(" 2. Reverse Array\n");
        printf(" 3. Sum of Elements\n");
        printf(" 4. Copy Array\n");
        printf(" 5. Count Duplicates\n");
        printf(" 6. Unique Elements\n");
        printf(" 7. Merge & Sort Descending\n");
        printf(" 8. Frequency of Elements\n");
        printf(" 9. Max & Min\n");
        printf("10. Odd & Even Separation\n");
        printf("11. Sort Ascending\n");
        printf("12. Sort Descending\n");
        printf("13. Delete at Position\n");
        printf("14. Second Largest\n");
        printf("15. Second Smallest\n");
        printf("16. 3x3 Matrix Input/Print\n");
        printf("17. Matrix Addition\n");
        printf("18. Matrix Subtraction\n");
        printf("19. Matrix Multiplication\n");
        printf("20. Transpose\n");
        printf("21. Sum of Right Diagonal\n");
        printf("22. Sum of Left Diagonal\n");
        printf("23. Row & Column Sums\n");
        printf("24. Lower Triangular\n");
        printf("25. Upper Triangular\n");
        printf("26. Determinant (3x3)\n");
        printf(" 0. Exit\n");
        printf("Choice: "); scanf("%d", &choice);

        switch (choice) {
            case  1: prog01(); break; case  2: prog02(); break;
            case  3: prog03(); break; case  4: prog04(); break;
            case  5: prog05(); break; case  6: prog06(); break;
            case  7: prog07(); break; case  8: prog08(); break;
            case  9: prog09(); break; case 10: prog10(); break;
            case 11: prog11(); break; case 12: prog12(); break;
            case 13: prog13(); break; case 14: prog14(); break;
            case 15: prog15(); break; case 16: prog16(); break;
            case 17: prog17(); break; case 18: prog18(); break;
            case 19: prog19(); break; case 20: prog20(); break;
            case 21: prog21(); break; case 22: prog22(); break;
            case 23: prog23(); break; case 24: prog24(); break;
            case 25: prog25(); break; case 26: prog26(); break;
            case  0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
