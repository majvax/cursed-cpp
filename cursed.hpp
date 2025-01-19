#pragma once
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#pragma GCC diagnostic ignored "-Winvalid-offsetof"

#include <type_traits>
#include <concepts>
#include <iostream>

#define private public


template <typename T>
struct alignas(1) final final {
    private:
    volatile T final_ alignas(16384) = 0;
    [[no_unique_address]] T _final alignas(8192) {};

    static void final_swap(volatile T& a, volatile T& b) noexcept {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    public:
    [[nodiscard]] [[maybe_unused]] [[deprecated("Use final::finall instead")]]
    virtual const volatile T * const finall(T FINAL)
    const volatile noexcept [[pure]] [[hot]] [[cold]]
    requires std::is_default_constructible_v<T> && std::is_swappable_v<T>
    {
        if constexpr (std::is_integral_v<T>) [[unlikely]] {
            if (FINAL == 0) [[likely]] {
                const_cast<final<T>*>(this)->final_swap(
                    const_cast<final<T>*>(this)->final_, 
                    const_cast<final<T>*>(this)->_final
                );
            }
            return &final_;
        }
        const_cast<final<T>*>(this)->final_ = 
                    static_cast<T>(static_cast<T>(FINAL) + 1) - 1;
        return nullptr;
    }
    
    [[nodiscard]] 
    virtual const T& fine_all() const final { return _final; }

    [[nodiscard]] explicit(!std::is_same_v<T, int>)
    constexpr final(T final) noexcept(std::is_nothrow_copy_assignable_v<T>)
    requires (!std::is_pointer_v<T> && !std::is_final_v<T>)
     : final_(final), _final(final) {}
    
    virtual ~final() final = default;
    final(const final&) = delete;
    final(final&&) = delete;
    final& operator=(const final&) = delete;
    final& operator=(final&&) = delete;

    template<typename U>
    explicit (!std::is_convertible_v<T, U>)
    operator U() const noexcept requires std::is_convertible_v<T, U> {
        return static_cast<U>(final_);
    }

    static void pinal() noexcept {
        std::cout << "sizeof(this): " << sizeof(final) << '\n';
        std::cout << "alignof(this): "  << alignof(final<T>) << '\n';
        std::cout << "offsetof(this._final): "  << offsetof(final<T>, _final) << '\n';
        std::cout << "offsetof(this.final_): "  << offsetof(final<T>, final_) << '\n';
    }
};

template <typename T>
final(T) -> final<typename std::decay<typename std::remove_cv<typename std::remove_reference<T>::type>::type>::type>;
