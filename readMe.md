Array intialisation - intialising array with 100 elements storing 0 at every index
	<!-- int *arr = new int[100]{0};  -->

some useful stl functions of #include<algorithm> - 
	- remove_if(arr<!-- (start position) -->, arr+n<!-- (end position) -->, predicateFunction); this remove_if function takes start and end position and remove elements where from the start till end the given predicate function returns true. This is a unary predicate which means it takes only one argument and returns a boolean value.

	- reverse_copy(v.begin(), v.end(), v.begin()<!-- as a resultant array beginning position) -->); copies the elements in reverse order from start to end but the resultant container stored reversed values begins with v.begin()

	- lower_bound(v.begin(), v.end(), value) returns an  iterator which points to the first element in the range start to end where the element of the container is >= with value specified. One other function similar to this is upper_bound(v.begin(), v.end(), value) which returns iterator to the first element from start to end range where the value is strictly > with the given value.

	- merge(arr1, arr1+5, arr2, arr2+5, v.begin()) merge function takes two arrays ranges and merge second array range at the end of first array with the resulting array sorted in increasing order and beginning value is pointed by the 5th parameter iterator of the merge function. It is to be noted that the ranges of two arrays should be sorted in any order(assending or descending)

	- next_permutation(arr, arr+n) returns true if the range of the arr can successfully permute to lexicographically greater pattern and also converts the range to that pattern(permutation) but it returns false if it cannot compute next permutation as lexicographically greater than the current and converts the array range to lowest possible(sorted in ascending order).


Useful string functions - 
	- s.substr(pos, size) returns a newly created substring of s starting with pos(index) with a size of 'size'.

	- s.resize(new_size, 'any_character") resize the original string eith the new_size and if the new_size is greater than previous string length then the "any_character" is appended to make the string upto the new length".


NOTE: Once the vector becomes full of elements it doubles its size and this doubling of size is very expensixe hence we should follow a approach of reserving the size of vector to some extent i.e. v.reserve(1000) it reserves 1000 blocks to the vector just like array and now the vector only doubles when all the 1000 blocks are occupied and we can observe that at higher size of vector the frequency of doubling operations lowers.