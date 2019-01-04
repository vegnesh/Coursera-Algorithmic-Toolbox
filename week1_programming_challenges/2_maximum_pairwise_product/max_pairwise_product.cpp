#include <iostream>
#include <vector>
#include <algorithm>


int64_t MaxPairwiseProduct(const std::vector<int>& numbers) {
    int64_t max_product = 0;
    int64_t maxmax = 0;
    int64_t maxmin = 0;
    int n = numbers.size();
    int index = -1;
    if(numbers[0]>numbers[1])
    {
      maxmax = numbers[0];
      maxmin = numbers[1];
    }
    else
    {
      maxmin = numbers[0];
      maxmax = numbers[1];
    }

    if(n>2)
    {
    for (int first = 2; first < n; ++first) {
     
      if( numbers[first] > maxmin)
      {
	if(numbers[first] >= maxmax)
	{
	  maxmin = maxmax;
	  maxmax = numbers[first];
	}
	else
	{
	  maxmin = numbers[first];

	}

      }
    

//        for (int second = first + 1; second < n; ++second) {
//            max_product = std::max(max_product,
//                numbers[first] * numbers[second]);
//        }
    }
    }


    max_product = maxmax * maxmin;

    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    int64_t result = MaxPairwiseProduct(numbers);
    std::cout << result << "\n";
    return 0;
}
