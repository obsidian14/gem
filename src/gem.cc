#include "gem.h"
#include <bit>
#include <cstdint>

namespace {
std::uint64_t bits(double f);

double from_bits(std::uint64_t f);

constexpr std::uint64_t sign = UINT64_C(1) << UINT64_C(63);

} // namespace

extern "C" {
double gem_abs(double f) { return from_bits(bits(f) & ~sign); }
}

namespace {
std::uint64_t bits(double f) { return std::bit_cast<std::uint64_t>(f); }

double from_bits(std::uint64_t f) { return std::bit_cast<double>(f); }
} // namespace
