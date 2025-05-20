# CP-Algos

A collection of classical C++ implementations of common algorithms and data structures tailored for competitive programming.

## 📝 Overview

This repository provides a curated set of tested, reusable implementations for algorithms frequently encountered in coding contests and algorithmic challenges. It is organized by topic, making it easy to find and integrate into your projects or competition codebase.

## 📂 Repository Structure

```
CP-Algos/
├── Number Theory/       # Prime sieves, SPF
├── String/              # String matching, hashing
├── README.md            # This file
└── LICENSE              # MIT License
```

> **Note:** If any directories are empty or missing, feel free to open an issue or submit a PR!

## 🚀 Getting Started

1. **Clone the repository**

   ```bash
   git clone https://github.com/JeetuGuptaa/CP-Algos.git
   cd CP-Algos
   ```

2. **Browse by topic**

   * Head into a directory (e.g., `Number Theory/`) to find source files.

3. **Compile an example**

   ```bash
   # Example: compile SPF sieve
   g++ -std=c++17 "Number Theory/spf_sieve.cpp" -O2 -o spf_sieve
   ./spf_sieve
   ```

4. **Integrate into your code**

   * Copy the required `.cpp` or `.h` files into your project or include them directly.

## 🎯 Features

* **Modularity:** Each algorithm is self-contained.
* **Readability:** Clear code with comments and consistent style.
* **Performance:** Optimized for typical contest constraints.

## 📖 Examples

```cpp
#include <iostream>
#include "Number Theory/spf_sieve.cpp"

int main() {
    const int N = 100000;
    SPF sieve(N);
    auto factors = sieve.getPrimeFactors(360);
    for (auto p : factors) std::cout << p << " ";  // 2 2 2 3 3 5
    std::cout << std::endl;
    return 0;
}
```

## 🤝 Contributing

Contributions are welcome! Please:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/YourFeature`
3. Commit your changes: \`git commit -m "Add new algorithm"
4. Push to the branch: `git push origin feature/YourFeature`
5. Open a pull request.

