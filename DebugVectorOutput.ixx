export module DebugVectorOutput;

import std;

// Overload to print the vector in segments
template <std::size_t Segments, typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    std::size_t count = 0;
    for (const auto& element : vec) {
        os << element;
        count++;
        if (count == Segments) {
            os << "\n";
            count = 0;
        }
        else {
            os << " ";
        }
    }
    return os;
}

// Overload to print unique elements with their counts
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    std::vector<T> uniqueVec;
    std::vector<std::size_t> uniqueCount;

    for (const auto& element : vec) {
        auto it = std::find(uniqueVec.begin(), uniqueVec.end(), element);
        if (it != uniqueVec.end()) {
            std::size_t index = std::distance(uniqueVec.begin(), it);
            uniqueCount[index]++;
        }
        else {
            uniqueVec.push_back(element);
            uniqueCount.push_back(1);
        }
    }

    for (std::size_t i = 0; i < uniqueVec.size(); ++i) {
        os << uniqueVec[i] << " " << uniqueCount[i] << "\n";
    }

    return os;
}
