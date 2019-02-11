/*
 * List.h
 *
 *  Created on: Jun 3, 2017
 *      Author: xinghuang
 */
#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include<assert.h>
#include <cstddef> //for NULL
using namespace std;
template <class listdata> //list stores generic listdata, not any specific C++ type

class List {
private:
    struct Node {
        listdata data;
        Node* nextnode;
        Node* previousnode;

        Node(listdata newdata) :
        data(newdata), nextnode(NULL),previousnode(NULL) {
        }
    };

    typedef struct Node* NodePtr;

    NodePtr begin;
    NodePtr end;
    void reverse(NodePtr node);

    //{
        //if(node)
       // {
            //reverse(node->nextnode);
            //cout<<node->data<<" ";
        //}
   // }



    //Helper function for the public printReverse() function.
    //Recursively prints the data in a List in reverse.
    bool isSorted(NodePtr node);
    //Helper function for the public isSorted() function.
    //Recursively determines whether a list is sorted in ascending order.
    int binarySearch(int low, int high,listdata data);
    //Recursively search the list by dividing the search space in half
    //Returns the index of the element, if it is found in the List
    //Returns -1 if the element is not in the List




    NodePtr iterator;
    int length;

public:


    /**Constructors and Destructors*/

    List();
    //Default constructor; initializes and empty list
    //Postcondition:

    List(const List&list);
    // copy constructor call
    ~List();
    /*
    ~List()
    {
        NodePtr temp = begin;
        NodePtr next = begin->nextnode;

        while (temp->nextnode != NULL)
        {
            delete temp;
            temp = next;
            next = temp->nextnode;
        }

    }
     */
    //Destructor. Frees memory allocated to the list
    //Postcondition:

    /**Accessors*/
    void printReverse();
    //Wrapper function that calls the reverse helper function to print a list in reverse
    //prints nothing if the List is empty

    bool empty() const;
    //Determines whether a list is empty.

    int getLength() const;
    //Returns the size of the list

    listdata getBegin() const;
    //Returns the first element in the list
    //Precondition: !empty()

    listdata getEnd() const;
    //Returns the last element in the list
    //Precondition: !empty()
    /**Manipulation Procedures*/

    void deleteBegin();
    //Removes the value of the first element in the list
    //Precondition: !empty()
    //Postcondition: the first element is removed


    void deleteEnd();
    //Removes the value of the last element in the list
    //Precondition:!empty()
    //Postcondition: the last element is removed

    void insertBegin(listdata data);
    //Inserts a new element at the start of the list
    //If the list is empty, the new element becomes both first and last
    //Postcondition: a new element is added before the iterator


    void insertEnd(listdata data);
    //Inserts a new element at the end of the list
    //If the list is empty, the new element becomes both first and last
    //Postcondition: a new element is added after the iterator

    /**Additional List Operations*/

    void print() const;
    //Prints to the console the value of each element in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty

    void beginIterator();
    //Moves the iterator to point to the first element in the list
    //If list is empty, the iterator remains NULL
    //Postcondition: A new element is added after where iterator is point now

    void insertIterator(listdata data);
    //insert a new element right after the iterator
    //pre: the iterator point to an element at the list
    //post: a new element added after the iterator

    void deleteIterator();
    //removes the element currently pointed to by the iterator. Iterator then points to NULL.
    //Precondition:The list should at least contain an element which pointed by iterator
    //Postcondition:The element which pointed by iterator is now removed

    bool offEnd();
    //the iterator is off the end of the list

    void advancedIterator();
    //Moves the iterator forward by one element
    //Precondition:Has no effect whether iterator is off end or list is empty
    //Postcondtion:iterator is point at next element in the list

    listdata getIterator() const;
    /*
    {
        return iterator->data;
    }
     */

    void reverseIterator();
    //Moves the iterator forward by one element
    //Precondition:Has no effect whether iterator is off end or list is empty
    //Postcondtion:iterator is point at before element in the list
    void printNumberedList() const;
    //print nothing if the list is empty

    bool operator == (const List &list);

    bool isSorted();
    //Wrapper function that calls the isSorted helper function to determine whether
    //a list is sorted in ascending order.
    //We will consider that a list is trivially sorted if it is empty.
    //Therefore, no precondition is needed for this function
    int getIndex();
    //Indicates the index of the Node where the iterator is currently pointing
    //Nodes are numbered from 1 to size of the list
    //Pre: length != 0
    //Pre: !offEnd()
    void advanceToIndex(int index);
    //Moves the iterator to the node whose index number is specified in the parameter
    //Pre: length != 0
    //Pre: index <= length
    int linearSearch(listdata data);
    //Searchs the list, element by element, from the start of the List to the end of the List
    //Returns the index of the element, if it is found in the List
    //Calls the above indexing functions in its implementation
    //Returns -1 if the element is not in the List
    //Pre: length != 0
    int binarySearch(listdata data);
    //Returns the index where data is located in the List
    //Calls the private helper function binarySearch to perform the search
    //Pre: length != 0
    //Pre: List is sorted (must test on a sorted list)



};


//#include<iostream>
//#include"List.h"
//using namespace std;
template <class listdata>
listdata List<listdata>::getIterator() const
{
    return iterator -> data;
}

template<class listdata>
void List<listdata>::printNumberedList() const {
    NodePtr temp = begin; //create a temporary iterator
    int i = 1;
    while (temp != NULL) {

        //Add two lines of code here
        //Hint: One statement should contain a cout
        if (temp->data ==NULL){
            std::cout << i << std::endl;
            temp = temp->nextnode;
            i++;
        } else{

            std::cout << i << ". <" << temp->data << "> " << std::endl;
            temp = temp->nextnode;
            i++;

        }
    }
    std::cout << std::endl; //change line after print the list

}

template<class listdata>
List<listdata>::List() {
    begin = NULL;
    end = NULL;
    iterator = NULL;
    length = 0;
    //count = 0;
}


 template<class listdata>
 List<listdata>::~List() {
 NodePtr after = begin;
 NodePtr before;
 while (after != NULL) {
 before = after->nextnode;
 delete after;
 after = before;

 }
 }


 template<class listdata>
 void List<listdata>::print() const
 {
     //int counter = 1;
     NodePtr temp = begin; //create a temporary iterator
     while (temp != NULL) {

         std::cout<< temp->data<<" ";
         temp = temp->nextnode;



     }
     std::cout << std::endl;

 }

template<class listdata>
void List<listdata>::insertBegin(listdata data) {
    if(length == 0) {
        NodePtr N = new Node(data);
        begin = end = N;
    } else {
        NodePtr N = new Node(data);
        N->nextnode = begin;
        begin->previousnode = N;
        begin = N;//why why why why why
    }
    length++;
}

template<class listdata>
void List<listdata>::insertEnd(listdata data)
{
    if(length==0)
    {
        begin = end = new Node(data);
    }
    else
    {
        NodePtr N = new Node(data);
        end->nextnode = N;
        N->previousnode = end;// this is what I add
        N->nextnode = NULL;
        end = N;

    }
    length++;
}



template<class listdata>
void List<listdata>::deleteBegin() {
    if (length == 0) {
        std::cout << "deleteBegin: List is empty. No data to remove." << std::

        endl;
    } else if (length == 1) {
        delete begin;
        begin = end = NULL;
        length = 0;

    } else {
        NodePtr temp = begin; //store this location so we don't lose access to it
        begin = begin->nextnode; //advance the pointer
        begin -> previousnode = NULL;//this is what I add
        delete temp; //free the memory for the original begin node
        length--;
    }
}


template<class listdata>
void List<listdata>::deleteEnd()
{
    if (length==0){

        std::cout<<"deleteEnd: is empty, nothing to remove"<<std::endl;

    } else if (length ==1) {

        delete end;
        begin = end = NULL;
        length = 0;

    } else {
        NodePtr temp = begin;
        while (temp->nextnode != end) {
            temp = temp->nextnode; //advance the pointer to find 2nd to last node
        }
        delete end; //free the memory for the original last node
        end = temp; //set the new end node
        end = end -> previousnode;//this is what I add
        end->nextnode = NULL; //so last->next is not pointing at freed memory
        length--;
    }

}


template<class listdata>
bool List<listdata>::empty() const
{
    return length == 0;
}

template<class listdata>
int  List<listdata>::getLength() const
{
    if(length==0)
    {
        return length == 0;
    }
    else{
        return length;
    }
}

template<class listdata>
listdata List<listdata>::getBegin() const
{
    return begin -> data;

}
template<class listdata>
listdata List<listdata>::getEnd() const
{
    return end->data;
}
template<class listdata>
void List<listdata>::beginIterator()
{
    iterator =  begin;
}
template<class listdata>
void List<listdata>::deleteIterator()
{
    assert(length != 0);

    if (iterator == end)

        deleteEnd();

    else if (iterator == begin)

        deleteBegin();

    else

    {

        NodePtr temp = iterator;

        iterator->previousnode->nextnode = iterator->nextnode;

        iterator->nextnode->previousnode = iterator->previousnode;

        iterator = NULL;

        delete temp;
    }

    length--;
}
template <class listdata>
void List<listdata>::advancedIterator()
{
    assert(!offEnd());

    if (offEnd())

        std::cout << " The list is off end." <<std::endl;

    else

        iterator = iterator->nextnode;

}
template <class listdata>
void List<listdata>::reverseIterator()
{
    assert(!offEnd());

    if (offEnd())

        std::cout << " The list is off end." <<std::endl;

    else

        iterator = iterator->previousnode;
}
template <class listdata>
void List<listdata>::insertIterator(listdata data)
{
    assert(!offEnd());

    if (offEnd())

        std::cout << "list is off ." << std::endl;
    else if (iterator == begin)
        insertBegin(data);

    else if (iterator == end)

        insertEnd(data);

    else

    {

        NodePtr N = new Node(data);

        N->nextnode = iterator->nextnode;

        iterator->nextnode = N;

        N->previousnode = iterator;

        N->nextnode->previousnode = N;

        length++;

    }

}
template <class listdata>
bool List<listdata>::offEnd()
{
    if(iterator == NULL)
    {
        return true;
    }
    else{
        return false;
    }
}


template <class listdata>
List<listdata>::List(const List &list):length(list.length)
{
    if(list.begin == NULL)
    {
        begin = end = iterator = NULL;
    }
    else
    {
        begin = new Node(list.begin->data);//calling Node Constructor
        NodePtr temp = list.begin;//set a temporary node pointer to point ar the first of the original list
        iterator = begin;//set iterator to point to firstnode of the newlist
        while(temp->nextnode!= NULL)
        {
            temp = temp ->nextnode;//advance up to the next node in the original list
            iterator ->nextnode = new Node(temp->data);//using node constructor to create newnode
            iterator = iterator -> nextnode;
        }
        end = iterator;
        iterator = NULL;
    }
}
template <class listdata>
void List<listdata>::reverse(NodePtr node)
{


	if(node!=NULL)
		{


		 std::cout<<node->data<<" ";
		  reverse(node->previousnode);

		}
	else
	{
		std::cout<<std::endl;
	}





}

template <class listdata>
void List<listdata>::printReverse()
{
    reverse(end);
}
template <class listdata>
bool List<listdata>::operator==(const List&list)
{
        if(length!=list.length)
        {
            return false;
        }
    NodePtr temp1 = begin;
    NodePtr temp2 = list.begin;
    while(temp1!=NULL)
    {
        if(temp1->data!=temp2->data)
        {
            return false;
        }
        temp1= temp1->nextnode;
        temp2= temp2->nextnode;
    }
    return true;
}
template <class listdata>
bool List<listdata>::isSorted(NodePtr node)
{
      if(node->nextnode==NULL)
      {
          return true;
      }
    else if((node->data)>(node->nextnode->data))
    {
        return false;

    }
    else{
        return isSorted(node->nextnode);
    }
}
template <class listdata>
bool List<listdata>:: isSorted()
{
     if(length==0)
     {
         return true;
     }
     else{
         return isSorted(begin);
     }
}
template <class listdata>
int List<listdata>::getIndex()
{
	assert(length!=0);
	//assert(!offEnd);  why I cannot add this line!!!!!!!!!!!

	NodePtr temp = begin;
    int index = 1;


        while(temp!=iterator)
        {

            temp = temp->nextnode;
            index++;
        }
        return index;
    //}
}
template <class listdata>
void List<listdata>::advanceToIndex(int index)
{
    assert(length!=0);
    assert(index<=length);
   NodePtr temp = begin;
    beginIterator();
    	    for(int i=1;i<=index;i++)
    	    {
    	        iterator = temp;
    	        temp = temp->nextnode;


    	    }

    }
/*
    else
    {
    	std::cout<<"The list is already off end"<<std::endl;
    }
    */



template <class listdata>
int List<listdata>::linearSearch(listdata data)
{
    assert(length!=0);
    NodePtr temp = begin;
    int position = 0;
    if(empty())
    {
        std::cout<<" The list is empty"<<std::endl;
        return -1;
    }
    else{
        while(temp!=NULL)
        {
            if(temp->data==data)
            {
                return (position+1);
            }
            else{
                temp=temp->nextnode;
                position++;
            }
        }
    }
    return -1;
}
template <class listdata>
int List<listdata>::binarySearch(int low,int high,listdata data)
{
    assert(length!=0);
    if(empty())
    {
        std::cout<<" the binarySearch list is empty"<<std::endl;
        return -1;
    }
    else{
           if(high<low)//it is must following the order which from the low to high
           {
            return -1;
           }
             int middle =low +(high-low)/2;
             advanceToIndex(middle);
             if(iterator->data==data)
             {
                return getIndex();
             }
             else if(data<iterator->data)
             {
                return binarySearch(low,middle-1,data);
             }
             else
             {
                return binarySearch(middle+1,high,data);
             }
        }

    return -1;
}

template<class listdata>
int List<listdata>::binarySearch(listdata data)
{

	   assert(length!=0);
	   assert(isSorted());

		return binarySearch(1,length,data);
}
//





#endif /* LIST_H_ */

