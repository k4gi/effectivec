// Objects, Functions, and Types   21
// Generally, C programmers need not concern themselves with align-
// ment requirements, because the compiler chooses suitable alignments for
// its various types. Dynamically allocated memory from malloc is required to
// be sufficiently aligned for all standard types, including arrays and struc-
// tures. However, on rare occasions, you might need to override the com-
// piler’s default choices; for example, to align data on the boundaries of the
// memory cache lines that must start at power-of-two address boundaries, or
// to meet other system-specific requirements. Traditionally, these require-
// ments were met by linker commands, or by overallocating memory with
// malloc followed by rounding the user address upward, or similar operations
// involving other nonstandard facilities.
// C11 introduced a simple, forward-compatible mechanism for specifying
// alignments. Alignments are represented as values of the type size_t. Every
// valid alignment value is a nonnegative integral power of two. An object
// type imposes a default alignment requirement on every object of that type:
// a stricter alignment (a larger power of two) can be requested using the
// alignment specifier (_Alignas). You can include an alignment specifier in
// the declaration specifiers of a declaration. Listing 2-7 uses the alignment
// specifier to ensure that good_buff is properly aligned (bad_buff may have
// incorrect alignment for member-access expressions).

struct S {
	  int i; double d; char c;
};

int main(void) {
	unsigned char bad_buff[sizeof(struct S)];
	_Alignas(struct S) unsigned char good_buff[sizeof(struct S)];
	
	struct S *bad_s_ptr = (struct S *)bad_buff;   // wrong pointer alignment
	struct S *good_s_ptr = (struct S *)good_buff; // correct pointer alignment
}
