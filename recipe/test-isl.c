#include <stdio.h>
#include <isl/set.h>

int main(void) {
	isl_ctx *ctx = isl_ctx_alloc();
	isl_set *set = isl_set_read_from_str(ctx,
		"{ [x, y] : x >= 0 and y >= 0 and x + y <= 10 }");
	isl_bool empty = isl_set_is_empty(set);
	isl_set_free(set);
	isl_ctx_free(ctx);

	if (empty != isl_bool_false) {
		fprintf(stderr, "isl smoke test failed: expected non-empty set\n");
		return 1;
	}
	printf("isl smoke test passed\n");
	return 0;
}
