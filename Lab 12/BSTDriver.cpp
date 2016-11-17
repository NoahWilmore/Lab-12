/*
	name: Jenny Haggerty && Noah Wilmore
	
	date:11/15
	
	reason: make a minnium hight tree 

*/


#include "BinarySearchTree.h"
#include "BinaryTreeIterator.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }

   delete iter;
}

int main()
{
   //the unsorted ListArray of cds
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int numItems = cds->size();
   cout << numItems << endl;
   cout << endl;

   //test the binary search tree
   //insert all of the cds
   ListArrayIterator<CD>* iter = cds->iterator();
   BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
   while(iter->hasNext())
	   //for(int i = 0; i < 40; i++)
   {
      CD* cd = iter->next();
      bst->insert(cd);
   }
   delete iter;

   BinaryTreeIterator<CD>* bst_iter = bst->iterator();
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->getKey()->displayString();
	  cout << endl;
   }
   delete bst_iter;

   //DO THIS
   //display the height of the binary search tree (not minimum height)
   //display whether the binary search tree is balanced (should not be balanced)

	cout << endl << "The height of the binary search tree is " << bst->getHeight() << endl;
	
	if (bst->isBalanced()){
		
		cout << "The binary search tree is balanced. " << endl << endl;
		
	}else{
		
		cout << "The binary search tree is NOT balanced. " << endl << endl;
	}

   //cout << "Testing to see if we get before the minimize section." << endl;
   //create a minimum height binary search tree
   BinarySearchTree<CD>* min_bst = bst->minimize();
   //cout << "Minimize completed." << endl;
   bst_iter = min_bst->iterator();

   //make sure that an inorder traversal gives sorted order
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->getKey()->displayString();
	  cout << endl;
   }
   delete bst_iter;

   //DO THIS
   //display the height of the binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced)

	cout << endl << "The height of the minimum height binary search tree is " << min_bst->getHeight() << endl;
	
	if (min_bst->isBalanced()){
		
		cout << "The minimum height binary search tree is balanced. " << endl << endl;
	
	}else{
		
		cout << "The minimum height binary search tree is NOT balanced. " << endl << endl;
	}

   //create a complete binary search tree
   BinarySearchTree<CD>* complete_bst = bst->minimizeComplete();
   delete bst;

   //make sure that an inorder traversal gives sorted order
   bst_iter = complete_bst->iterator();
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->displayCD();
   }
   delete bst_iter;

   //DO THIS
   //display the height of the complete binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced)

	cout << "The height of the complete binary search tree is " << complete_bst->getHeight() << endl;
	
	if (complete_bst->isBalanced()){
		
		cout << "The complete binary search tree is balanced. " << endl;
		
	}else{
		
		cout << "The complete binary search tree is NOT balanced. " << endl;
	}

   delete complete_bst;

   deleteCDs(cds);
   delete cds;
   return 0;
}
