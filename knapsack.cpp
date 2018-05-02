#include <iostream>
#include <algorithm>    // for std::max

using namespace std;

//heavily referenced from: https://www.geeksforgeeks.org/knapsack-problem/

//INPUT: 
//	itemCount: the number of items we can select from
//	weights[]: an array of weights, one for each item
//	values[]: an array of values, one for each item
//	capacity: the total capacity of the knapsack (aka the maximum amount of weight the knapsack can hold)
int knapsack(int itemCount, int weights[], int values[], int capacity)
{
	//define two cursors for the table we're going to build
	int currentItem;	//the row cursor
	int weight;			//the column cursor
	
	//the solution cache, cache[i][j] stores the optimal value for a set of items selected from items 0-j, given a knapsack of capacity j
	int cache[itemCount+1][capacity+1];	//need to add one more index to each dimension to account for the cases where there are 0 items or the capacity is 0
	
	for (currentItem=0; currentItem <= itemCount; currentItem++)	//for each row in the cache
	{
		for (weight=0; weight <= capacity; weight++)	//for each column in the cache
		{
			//the first row and the first column are all 0's, because no items or no capacity means you can only ever get 0 value
			if (currentItem == 0 || weight == 0)
				cache[currentItem][weight] = 0;
				
			//the currentItem can't fit into the knapsack
			else if (weights[currentItem-1] > capacity) 
				cache[currentItem][weight] = cache[currentItem-1][weight]; //so the maximum for this capacity is the maximum for the currentItem set WITHOUT the current item
			
			//the current item can fit into the knapsack, is the combination WITH the current item worth more than the best combination WITHOUT the current item? Choose the max	
			else 	
				cache[currentItem][weight]= max(values[currentItem-1] + cache[currentItem-1][weight-weights[currentItem-1]], cache[currentItem-1][weight]);			
		}
	}
	return cache[itemCount][capacity];
}