#pragma once

namespace pre_post_operations {
	template <typename T>
	struct PostProxy {
		T* that_ = nullptr;

		PostProxy(T* that) noexcept : that_{ that } {}
		~PostProxy() { that_->post_operation(); }

		T* operator->() noexcept {
			return that_;
		}

		T const* operator->() const noexcept {
			return that_;
		}
	};

	template <typename T>
	struct PrePostOperations {
		virtual void pre_operation() {
			std::printf("pre operation. ");
		}

		virtual void pre_operation() const {
			std::printf("const pre operation. ");
		}

		virtual void post_operation() {
			std::printf("post operation. \n");
		}

		virtual void post_operation() const {
			std::printf("const post operation. \n");
		}

		PostProxy<T> operator->() {
			pre_operation();
			return{ static_cast<T*>(this) };
		}

		PostProxy<T const> operator->() const {
			pre_operation();
			return{ static_cast<T const*>(this) };
		}
	};
}