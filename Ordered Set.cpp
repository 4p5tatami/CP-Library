/*
order_of_key (k) : Number of items strictly smaller than k
find_by_order(k) : k-th element in a set (counting from zero)
for multiset, use less_equal<int>. lower_bound and upper_bound functions are reversed
do not use find to locate elements, use lower_bound/upper_bound instead
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set; 	

