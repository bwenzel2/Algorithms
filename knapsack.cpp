#include <iostream>
#include <algorithm>    // for std::max

using namespace std;

//heavily referenced from: https://www.geeksforgeeks.org/knapsack-problem/
int knapsack(int itemCount, int weights[], int values[], int capacity)
{
	int currentItem;
	int weight;
	
	//the solution cache, cache[i][j] stores the optimal value for a set of items selected from items 0-j, given a knapsack of capacity j
	int cache[itemCount+1][capacity+1];
	
	for (currentItem=0; currentItem <= itemCount; currentItem++)	//for each row in the cache
	{
		for (weight=0; weight <= capacity; weight++)	//for each column in the cache
		{
			if (currentItem == 0 || weight == 0)	//the first row and the first column are all 0's
				cache[currentItem][weight] = 0;
			else if (weights[currentItem-1] > capacity) //the currentItem can't fit into the knapsack
				cache[currentItem][weight] = cache[currentItem-1][weight]; //so the maximum for this capacity is the maximum for the currentItem set WITHOUT the current item
			else 	
				cache[currentItem][weight]= max(values[currentItem-1] + cache[currentItem-1][weight-weights[currentItem-1]], cache[currentItem-1][weight]);			
		}
	}
	return cache[itemCount][capacity];
}