#  Time Complexity Table (for n = 10^5)

| Complexity | Steps (approx) | Feasibility |
|------------|----------------|-------------|
| **O(1)**   | 1              | Instant  |
| **O(log n)** | ~17 (since log₂(100000) ≈ 17) | Super fast  |
| **O(n)**   | 100,000        | Very fast |
| **O(n log n)** | 100,000 × 17 ≈ 1.7M | Still fast  (common in sorting) |
| **O(n²)**  | (10^5)² = 10^10 | Too large  (takes hours) |
| **O(n³)**  | (10^5)³ = 10^15 | Impossible  |
| **O(2^n)** | 2^100000 (huge) | Not computable  |
| **O(n!)**  | Factorial of 100000 | Beyond impossible  |
