#include <iostream>
#include "Data.h"

using std::cout;

template<class T, class E>
class HashTable {
private:
	int len;
	int count;
	Data<T, E> *items = NULL;
	Data<T, E> data;
	
public:
	HashTable() {
		len = 8;
		count = 0;
		items = new Data<T, E>[len];
		
		for(int i = 0; i < length(); i++)
		{
			items[i].key = -1;
			items[i].value = 0;
		}
	}
	
	bool put(T key, E value) 
	{
	
		data.key = key;
		data.value = value;
		
		int index = hash(data.key);
		
		if(items[index].key == -1) 
		{
			items[index] = data;
		}
		else
		{
			int timer = 0;
		
			while(items[index].key != -1 && items[index].key != data.key) // items[index].key = 1 , data.key = 11
			{
				index++;
				
				if(index >= len)
				{
					index = index % len;
					
					if(timer++ >= 1) return false;
				}
			}
		}
		
		count++;
		items[index] = data;
		return true;
	}
	
	E get(T key)
	{
		int index = hash(key);
		
		if(items[index].key == key)
		{
			return items[index].value;
		}
		
		int timer = 0;
		
		while(items[index].key != key)  // 9 -> hash(15) = 1. index = 1 
		{
			index++;
	
			if(index >= len)
			{
				index = index % len;
				
				if(timer++ >= 1) return -1;
			}
			
		}
		
		return index[items].value;
	}
	
	void print()
	{
		cout<<"[";
		
		for(int i = 0; i < length(); i++)
		{
			
			cout<<items[i].key<<": "<<items[i].value;
			
			if(i+1 < length()) cout<<", ";
			
		}
		cout<<"]";
	}
	
	int size() { return count; }
	
private:
	int length() { return len; }
	
	int hash(T key)
	{
		return key % length();
	}
};
