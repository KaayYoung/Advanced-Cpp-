#ifndef STRINGQUEUE_H_
#define STRINGQUEUE_H_

#include <memory>
#include <stdexcept>
#include <string>

template<typename T>
class stringqueue {
public:
	explicit stringqueue()
	: stringqueue(5){}

	explicit stringqueue(int size)
	: size_curr_{0}
	, size_max_{size}
	// NOLINTNEXTLINE
	, queue_{std::make_unique<T[]>(size)} {}

	stringqueue(stringqueue const& q) {
		size_max_ = q.size_max_;
		size_curr_ = q.size_curr_;
		// NOLINTNEXTLINE
		queue_ = std::make_unique<T[]>(size_max_);
		for (int i = 0; i < size_curr_; ++i) {
			queue_[i] = q.queue_[i];
		}
	}
	auto enque(T s) -> void;
	auto deque() -> T;
	[[nodiscard]] auto size() const -> int;

private:
	int size_curr_;
	int size_max_;
	// NOLINTNEXTLINE
	std::unique_ptr<T[]> queue_;
};

template<typename T>
auto stringqueue<T>::enque(T s) -> void {
	if (size_curr_ + 1 >= size_max_) {
		throw std::overflow_error{"stringqueue is full"};
	}
	queue_[size_curr_] = s;
	size_curr_ += 1;
}

template<typename T>
auto stringqueue<T>::deque() -> T {
	if (size_curr_ == 0) {
		throw std::logic_error{"No items in queue"};
	}
	T item = queue_[0];
	for (auto i = 1; i <= size_curr_; ++i) {
		queue_[i - 1] = queue_[i];
	}
	size_curr_--;
	return item;
}

template<typename T>
auto stringqueue<T>::size() const -> int {
	return size_curr_;
}

#endif // STRINGQUEUE_H_