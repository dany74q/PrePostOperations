#include "pre_post_operations.h"
#include <cstdio>

using namespace pre_post_operations;

struct UsingPrePostOperations : PrePostOperations<UsingPrePostOperations> {
	void func() { std::printf("func. "); }
};

struct UsingCustomPrePostOperations : PrePostOperations<UsingCustomPrePostOperations> {
	void pre_operation() override { std::printf("custom pre operation. "); }
	void post_operation() override { std::printf("custom post operation.\n"); }
	void func() { std::printf("func. "); }
};

struct UsingCustomPrePostOperationsConst : PrePostOperations<UsingCustomPrePostOperationsConst> {
	void pre_operation() const override { std::printf("custom const pre operation. "); }
	void post_operation() const override { std::printf("custom const post operation.\n"); }
	void func() const { std::printf("const func. "); }
};

int main() {
	UsingPrePostOperations prePost;
	// Will print 'pre operation. func. post operation.'
	prePost->func();

	UsingCustomPrePostOperations customPrePost;
	// Will print 'custom pre operation. func. custom post operation.'
	customPrePost->func();

	const UsingCustomPrePostOperationsConst constCustomPrePost;
	// Will print 'custom const pre operation. const func. custom const post operation.'
	constCustomPrePost->func();
}