#include <bits/extc++.h>                         // pbds
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> ost;

/*
 *
 * Usage:
 * less / greater
 * it has the same operations with c++ set
 * find_by_order() -> returns an iterator to the k-th largest element(counting from zero)
 * order_of_key() -> the number of items in a set that are strictly smaller(< x) than our item 
 *
*/

