CC = gcc         // C compiler
CFLAGS = -Wall   // Compiler flags

all: run        // Default target

build: pointers reverse_traversal two_pointers WithoutExtraVar XOR    // Build all executables

pointers: pointers.c              // Build pointers executable
	$(CC) $(CFLAGS) -o pointers pointers.c

reverse_traversal: reverse_traversal.c          // Build reverse_traversal executable
	$(CC) $(CFLAGS) -o reverse_traversal reverse_traversal.c

two_pointers: two_pointers.c                // Build two_pointers executable
	$(CC) $(CFLAGS) -o two_pointers two_pointers.c

WithoutExtraVar: WithoutExtraVar.c              // Build WithoutExtraVar executable
	$(CC) $(CFLAGS) -o WithoutExtraVar WithoutExtraVar.c

XOR: XOR.c                    // Build XOR executable
	$(CC) $(CFLAGS) -o XOR XOR.c

run: build
	@echo "Running Pointers Approach"
	./pointers
	@echo ""
	@echo ""
	@echo "Running Reverse Traversal Approach"
	./reverse_traversal
	@echo ""
	@echo ""
	@echo "Running Two Pointers Approach"
	./two_pointers
	@echo ""
	@echo ""
	@echo "Running Without Extra Variable"
	./WithoutExtraVar
	@echo ""
	@echo ""
	@echo "Running XOR"
	./XOR
	@echo ""

clean:
	rm -f pointers reverse_traversal two_pointers WithoutExtraVar XOR
