// *******************************************************
// *                                                     *
// *  avltree.h                                          *
// *                                                     *
// *  Interface for an AVL tree, which was designed      *
// *  in the spirit of the C++ STL interfaces and        *
// *  which can (among other things) be used to          *
// *  implement the map class.                           *
// *                                                     *
// *  Current version written July 2001 by Jason Zych    *  
// *  Adapted from previous work done by Wendy L. Terry  *
// *    and Jason Zych from 1997 - 2001.                 *
// *                                                     *
// *  Still needs some work here and there with const    *
// *  correctness; this should be completed by the end   *
// *  of July 2001.                                      *
// *                                                     *
// ******************************************************* 

/*  
   TO THE CS225 STUDENT:


   This file will at first look large and difficult
   to understand. It will make more sense if you realize
   that it is grouped into four sections as follows:


     (1) typedefs

         This first section is not terribly important to you
         right now and you can skip over it if you like. We've
         designed the file so that it can be ignored until you
         specifically want to use these tools. 

         A "typedef" is a type definition. You are taking an
         existing type, and assigning it an additional name. 
         These "new names" are standard names that exist for 
         every STL class. The idea is that if you are given
         some container object myObj, and you don't know whether 
         it is a vector, or a list, or whatever, you can still say
         myObj::value_type, and that expression will give you
         the type of the value held in this container.


     (2) iterators

         Four kinds of iterators are defined, all of which are
         pretty similar, so once you understand one, you're not
         too far from understanding them all:
 
             iterator 
             const_iterator  
                  same as iterator except you can only read
                  the container through this iterator, not alter it
             reverse_iterator  
                  same as iterator except that moving from begin()
                  to end() moves you from the end to the front of
                  the container, rather than vice-versa as with iterator
             const_reverse_iterator
                  same as reverse_iterator except you can only read 
                  the container through this iterator, not alter it

         Note that all the definition code for the iterators
         appears inside the iterator class declarations, rather
         than in the .C. There are reasons for this that we're not
         going to get into right now; suffice to say that it's okay,
         but that you should *not* do that in code you write for this
         course.  :-)

     (3) the declarations for the AVL member functions themselves

         the avltree.C file contains the code for the functions in
          section (3). 


     (4) private data and private member functions 
     
         the avltree.C file contains the code for the functions in
          section (4). 

*/



#ifndef AVLTREE_H
#define AVLTREE_H

#include <stddef.h>
#include "asserts.h"
#include "utility225.h"

// **************************************************************
// *                                                            *
// *  Class : avl_tree                                          *
// *                                                            *
// *  The interface class for the AVL implementation            * 
// *                                                            *
// **************************************************************

template <class Ktype, class Etype>
class avl_tree 
{
private:   // there is another private section later on, this
           // one is only for the forward declaration below 

   class avl_tree_node;  // forward declaration, so that we
                         // can use "avl_tree_node" as a type in
                         // our iterator class before it is
                         // formally declared further down in the
                         // file. 
   

public:


   // *****************************************
   // *                                       *
   // *  Section 1: typedefs                  *
   // *                                       *
   // *****************************************

   // All STL container classes define 12 types. We
   // have them all represented below, though, as we
   // indicate, some of them will not be relevant for this class.
   // Associative containers like maps, and the trees that
   // implement them, also have a few more types beyond the 
   // standard 12. 


   // Types 1-5 : referring to the elements held by this vector
   // 
   typedef pair<const Ktype, Etype> value_type;   // the type this tree holds
   typedef value_type* pointer;     // pointer to type tree holds
   typedef const value_type* const_pointer;  // like "pointer" but const
   typedef value_type& reference; // a reference var to the type the tree holds
   typedef const value_type& const_reference; // like "reference" but const


   // Types 6-9 : iterators for this tree
   //  
   // Declarations/definitions for
   //    iterator
   //    const_iterator
   //    reverse_iterator
   //    const_reverse_iterator
   // appear below. In most implementations, only iterator
   // and const_iterator are defined, and the two "reverse"
   // classes are created using a special template located
   // in a different file. We've simplified things a bit
   // for you by sticking it all in here, but as a result,
   // you will note that the code for every reverse_iterator  
   // in every CS225 STL container class looks exactly the same. 
 
 
   // Types 10-12 : allocator-specific types
   // 
   // The declarations  
   //    allocator_type
   //    size_type
   //    difference_type
   //  will not be used in this course. In actual STL classes,
   //  when you create a container object, there are *two* templates
   //  you can fill in -- the type the container holds (which we
   //  have too), and a specific memory management object called 
   //  an "allocator". That second one is more obscure, and we've
   //  decided not to make it part of our own implementation of these
   //  classes so that you can focus on the more-frequently-used 
   //  parts of the STL. But we at least wanted you to know it 
   //  existed, and if it did, we'd need the final three types above
   //  as well.  


   // Types 13-16 : specific for associative containers
   // 
   // Two of these we will use, and two of these we will not. 
   // The two we don't use, we are not using because we're not
   // dealing with "function objects" yet. So we will not 
   // give a type declaration for
   //    key_compare
   //    value_compare
   // but instead will just assume that < is what we are using
   // to compare keys. 

   typedef Ktype key_type;  // type 15, the key of this tree
   typedef Etype mapped_type;  // type 16, what we map to in this tree

  

   // *****************************************
   // *                                       *
   // *  Section 2: iterator classes          *
   // *    iterator                           *
   // *    const_iterator                     *
   // *    reverse_iterator                   *
   // *    const_reverse_iterator             * 
   // *                                       *
   // *****************************************


   // *********************************************
   // *                                           *
   // *  avl_tree<>::iterator                     *
   // *                                           *
   // *  standard iterator for our AVL tree class *
   // *                                           *
   // *********************************************

   class iterator 
   {
   public:
     
      // iterator
      //    - default constructor 
      //    - creates a null iterator 
      iterator() { ptr = NULL; }


      // operator==
      //    - parameters : origVal - another iterator
      //    - return type : boolean integer
      //    - returns 1 if this iterator and the parameter
      //       iterator point to the same location, 0 else.
      int operator==(const iterator& origVal) const
          { return (ptr == origVal.ptr); }


      // operator!=
      //    - parameters : origVal - another iterator
      //    - return type : boolean integer
      //    - returns 1 if this iterator and the parameter
      //       iterator do NOT point to the same location, 0 else.
      int operator!=(const iterator& origVal) const
          { return (ptr != origVal.ptr); }


      // operator*
      //    - return type : reference to a node value
      //    - returns the value pointed to by this iterator
      pair<Ktype, Etype>& operator*() { return ptr->element; }


      // operator->
      //    - return type : reference to a node value
      //    - returns the address of the value in the node
      //         pointed to by this iterator
      pair<Ktype, Etype>* operator->()  { return &(ptr->element); } 

   
      // operator++ (prefix)
      //    - return type : an iterator
      //    - moves the iterator to the next value in the
      //        sequence. If you are at the final, "null"
      //        element, an error message is printed instead
      //        since there is no element to move to. 
      iterator& operator++() 
      {   
         // if our iterator points to the header node, meaning
         //   there is no in order successor for this iterator's node,
         //   then either we are at end(), or else we are at
         //   begin() in an empty tree, which is the same as end()
         //   in that tree. In either case, you can't ++ from end(),
         //   so it's error message time. 
         //
         //   Our "header" node is set to have a height of zero,
         //   yet point to the leftmost and rightmost values of the
         //   tree, or itself if the tree is empty. So, the left and
         //   right pointers of the "header" are never NULL. Thus, if
         //   our node has height 0 and yet does not have two NULL pointers
         //   for children, it must be the header node.
         if ((ptr->height == 0) && (ptr->left != NULL))
            cerr << "trying ++ on null iterator" << endl;  

         // otherwise, if this node has a right subtree, then its 
         //  inorder successor is below, in that subtree
         else if (ptr->right != NULL)
         {
            ptr = ptr->right;
            while (ptr->left != NULL)
               ptr = ptr->left;
         }

         // otherwise, this node's inorder successor is *above* it,
         // an ancestor of it
         else   // ptr->right == NULL
         {
            // Once we know the inorder successor is an ancestor, 
            //  there are three possibilities at any node as we move 
            //  upward, searching for the inorder successor:
            //   1) if the node we are at is its parent's left child,
            //     then the parent of the node we are at is the inorder
            //     successor we are looking for; LOOP CAN STOP
            //   2) if the node we are at is its parent's right child,
            //     then the inorder successor is an ancestor of the 
            //     parent of the node we are looking at; LOOP MUST CONTINUE
            //   3) if the node we are at does not have a parent, then
            //     it is the root, and the inorder successor we are
            //     looking for does not exist; LOOP CAN STOP

            // while parent isn't header node, and we are right child
            //   of parent 
            while((ptr->parent->height != 0) && (ptr->parent->right == ptr))
               ptr = ptr->parent;

            // if we stopped, it is because we are left child of parent
            // or because we are the root. Either way, what the parent 
            // pointer points to is what we want.  
            ptr = ptr->parent;
         }
         return *this;
      }



      // operator++ (postfix)
      //    - return type : an iterator
      //    - postfix version of operator++, performs ++ on
      //        the iterator, but returns the old value, not the
      //        new one
      iterator operator++(int)
      {
         iterator temp = *this;
         ++(*this);
         return temp;
      }


      // operator-- (prefix)
      //    - return type : an iterator
      //    - moves the iterator to the previous value in the
      //        sequence. If you are at the first 
      //        element, an error message is printed instead
      //        since there is no element to move to. 
      iterator& operator--() 
      { 
         // if we are at the header node, then either:
         //   - we are at the node given by end() in a non-empty
         //      tree, in which case its inorder predecessor is the 
         //      rightmost node in the tree
         //   - we are at the node given by end() and begin() in
         //      an empty tree, in which case we cannot get the
         //      inorder predecessor because there isn't one. It's
         //      therefore error message time. 
         if ((ptr->height == 0) && (ptr->left != NULL))
         {
            // if there is a rightmost, move to it.
        
            if (ptr->right != ptr)
               ptr = ptr->right;
            // if there is not, then we are at End() but there
            //   are no previous nodes...that means End() equals
            //   Begin() and the tree is empty.
            else
               cerr << "trying to op-- when we can't" << endl;
         }
         // otherwise, if this node has a left subtree, then its
         // inorder precessor is below it, in that subtree.
         else if (ptr->left != NULL)
         {
            ptr = ptr->left;
            while (ptr->right != NULL)
               ptr = ptr->right;
         }
  
         // otherwise, this node's inorder predecessor is *above*
         // it, an ancestor of it. 
         else   // ptr->left == NULL
         {
            // Once we know the inorder predeccessor is an ancestor, 
            //  there are three possibilities at any node as we move 
            //  upward, searching for the inorder successor:
            //   1) if the node we are at is its parent's left child,
            //     then the inorder predecessor is an ancestor of the 
            //     parent of the node we are looking at; LOOP MUST CONTINUE
            //   2) if the node we are at is its parent's right child,
            //     then the inorder predecessor of the node we are 
            //     looking at is its parent; LOOP CAN STOP
            //   3) if the node we are at is the root, then our original
            //      node must have been the leftmost node, which has
            //      no inorder predecessor. Break out the error message!

            // while we are left child of parent
            while ((ptr->parent->height != 0) && (ptr->parent->left == ptr))
               ptr = ptr->parent;

            // if we stopped, it is because we are right child of parent
            //  or because we are at root. In the former case, the parent is
            //  what we want. In the latter, go for the error message.  
            Assert(ptr->parent->height != 0, 
                     "cannot decrement an iterator pointing to begin()");
               ptr = ptr->parent;
         }
         return *this;
      }



      // operator-- (postfix)
      //    - return type : an iterator
      //    - postfix version of operator--, performs -- on 
      //       iterator but returns the old value, not the
      //       new one
      iterator operator--(int) 
      { 
         iterator temp = *this;
         --(*this);
         return temp;
      }



   private:

      // this exists so that avl_tree functions can freely get
      //  to the constructor below.
      friend class avl_tree<Ktype, Etype>;

      avl_tree_node* ptr; // the pointer to the node type that
                          // the iterator class controls access to

      // iterator
      //    - constructor
      //    - parameters : assignPtr - pointer to store in this
      //                       iterator
      //    - initializes iterator to point to same node as
      //        assignPtr. This function must be private to
      //        protect encapsulation. Right now, clients can
      //        only set iterators to other iterators; if this
      //        function were public, they could set iterators
      //        to any address, thereby breaking the protective
      //        wrapper of encapsulation around the iterator's 
      //        member data (its internal pointer).
      iterator(avl_tree_node* assignPtr) { ptr = assignPtr; }

   };




   // *********************************************
   // *                                           *
   // *  avl_tree<>::const_iterator               *
   // *                                           *
   // *********************************************

   class const_iterator 
   {
   public:
     
      // const_iterator
      //    - default constructor 
      //    - creates a null iterator 
      const_iterator() { ptr = NULL; }


      // operator==
      //    - parameters : origVal - another iterator
      //    - return type : boolean integer
      //    - returns 1 if this iterator and the parameter
      //       iterator point to the same location, 0 else.
      int operator==(const const_iterator& origVal) const
          { return (ptr == origVal.ptr); }


      // operator!=
      //    - parameters : origVal - another iterator
      //    - return type : boolean integer
      //    - returns 1 if this iterator and the parameter
      //       iterator do NOT point to the same location, 0 else.
      int operator!=(const const_iterator& origVal) const
          { return (ptr != origVal.ptr); }


      // operator*
      //    - return type : reference to a node value
      //    - returns the value pointed to by this iterator
      const pair<Ktype, Etype>& operator*() { return ptr->element; }


      // operator->
      //    - return type : reference to a node value
      //    - returns the address of the value in the node
      //         pointed to by this iterator
      const pair<Ktype, Etype>* operator->()  { return &(ptr->element); } 

   
      // operator++ (prefix)
      //    - return type : an iterator
      //    - moves the iterator to the next value in the
      //        sequence. If you are at the final, "null"
      //        element, an error message is printed instead
      //        since there is no element to move to. 
      const_iterator& operator++() 
      {   
         // Comments can be read in the iterator class; code is 
         // the same here. 
         if ((ptr->height == 0) && (ptr->left != NULL))
            cerr << "trying ++ on null iterator" << endl;  
         else if (ptr->right != NULL)
         {
            ptr = ptr->right;
            while (ptr->left != NULL)
               ptr = ptr->left;
         }
         else   // ptr->right == NULL
         {
            while((ptr->parent->height != 0) && (ptr->parent->right == ptr))
               ptr = ptr->parent;
            ptr = ptr->parent;
         }
         return *this;
      }



      // operator++ (postfix)
      //    - return type : an iterator
      //    - postfix version of operator++, performs ++ on
      //        the iterator, but returns the old value, not the
      //        new one
      const_iterator operator++(int)
      {
         const_iterator temp = *this;
         ++(*this);
         return temp;
      }



      // operator-- (prefix)
      //    - return type : an iterator
      //    - moves the iterator to the previous value in the
      //        sequence. If you are at the first 
      //        element, an error message is printed instead
      //        since there is no element to move to. 
      const_iterator& operator--() 
      { 
         // Comments can be read in the iterator class; code is
         //  the same here. 
         if ((ptr->height == 0) && (ptr->left != NULL))
         {
            if (ptr->right != ptr)
               ptr = ptr->right;
            else
               cerr << "trying to op-- when we can't" << endl;
         }
         else if (ptr->left != NULL)
         {
            ptr = ptr->left;
            while (ptr->right != NULL)
               ptr = ptr->right;
         }
         else   // ptr->left == NULL
         {
            while ((ptr->parent->height != 0) && (ptr->parent->left == ptr))
               ptr = ptr->parent;
            Assert(ptr->parent->height != 0, 
                     "cannot decrement an iterator pointing to begin()");
               ptr = ptr->parent;
         }
         return *this;
      }



      // operator-- (postfix)
      //    - return type : an iterator
      //    - postfix version of operator--, performs -- on 
      //       iterator but returns the old value, not the
      //       new one
      const_iterator operator--(int) 
      { 
         iterator temp = *this;
         --(*this);
         return temp;
      }



   private:


      // without this line, the avl_tree class can't use the
      // constructor below
      friend class avl_tree<Ktype, Etype>;


      avl_tree_node* ptr; // the pointer to the node type that
                          // the iterator class controls access to

      // const_iterator
      //    - constructor
      //    - parameters : assignPtr - pointer to store in this
      //                       iterator
      //    - initializes iterator to point to same node as
      //        assignPtr. This function must be private to
      //        protect encapsulation. Right now, clients can
      //        only set iterators to other iterators; if this
      //        function were public, they could set iterators
      //        to any address, thereby breaking the protective
      //        wrapper of encapsulation around the iterator's 
      //        member data (its internal pointer).
      const_iterator(avl_tree_node* assignPtr) { ptr = assignPtr; }

   };





   // *********************************************
   // *                                           *
   // *  avl_tree<>::reverse_iterator             *
   // *                                           *
   // *********************************************

   class reverse_iterator
   {
   public:

      // reverse_iterator
      //    - default constructor 
      //    - creates a null reverse iterator 
      reverse_iterator() : current() {}


      // operator==
      //    - parameters : origVal - another reverse iterator
      //    - return type : boolean integer
      //    - returns 1 if this reverse iterator and the parameter
      //       iterator point to the same location, 0 else.
      int operator==(const reverse_iterator& origVal) const
          { return (current == origVal.current); }


      // operator!=
      //    - parameters : origVal - another reverse iterator
      //    - return type : boolean integer
      //    - returns 1 if this reverse iterator and the parameter
      //       iterator do NOT point to the same location, 0 else.
      int operator!=(const reverse_iterator& origVal) const
          { return (current != origVal.current); }


      // operator*
      //    - return type : reference to a node value
      //    - returns the value pointed to by this reverse iterator
      pair<Ktype, Etype>& operator*() 
      { 
         iterator temp = current;
         return *(--temp); 
      }


      // operator->
      //    - return type : reference to a node value
      //    - returns the address of the value in the node
      //         pointed to by this reverse iterator
      pair<Ktype, Etype>* operator->()  { return &(operator*()); }


      // operator++ (prefix)
      //    - return type : a reverse iterator
      //    - moves the iterator to the next value in the
      //        reverse sequence. If you are at the final, "null"
      //        element, an error message is printed instead
      //        since there is no element to move to. 
      reverse_iterator& operator++() { --current; return *this; }

      // operator++ (postfix)
      //    - return type : a reverse iterator
      //    - postfix version of operator++
      reverse_iterator operator++(int)
      {
         reverse_iterator temp = *this;
         --current;
         return temp;
      }


      // operator-- (prefix)
      //    - return type : a reverse iterator
      //    - moves the iterator to the previous value in the
      //        reverse sequence. If you are at the first 
      //        element, an error message is printed instead
      //        since there is no element to move to. 
      reverse_iterator& operator--() { ++current; return *this; }



      // operator-- (postfix)
      //    - return type : a reverse iterator
      //    - postfix version of operator--
      reverse_iterator operator--(int)
      {
         reverse_iterator temp = *this;
         ++current;
         return temp;
      }



   private:
    
      friend class avl_tree<Ktype, Etype>;

      iterator current;    // A reverse_iterator is just
                           // a special interface wrapper
                           // around a "forward iterator".


      // reverse_iterator
      //    - constructor
      //    - parameters : assignPtr - pointer to store in this
      //                       iterator
      //    - initializes iterator to point to same node as
      //        assignPtr. This function must be private to
      //        protect encapsulation. Right now, clients can
      //        only set iterators to other iterators; if this
      //        function were public, they could set iterators
      //        to any address, thereby breaking the protective
      //        wrapper of encapsulation around the iterator's 
      //        member data (its internal pointer).
      reverse_iterator(iterator x) : current(x) {}

   };





   // *********************************************
   // *                                           *
   // *  avl_tree<>::const_reverse_iterator       *
   // *                                           *
   // *********************************************

   class const_reverse_iterator
   {
   public:

      // const_reverse_iterator
      //    - default constructor 
      //    - creates a null reverse iterator 
      const_reverse_iterator() : current() {}


      // operator==
      //    - parameters : origVal - another reverse iterator
      //    - return type : boolean integer
      //    - returns 1 if this reverse iterator and the parameter
      //       iterator point to the same location, 0 else.
      int operator==(const const_reverse_iterator& origVal) const
          { return (current == origVal.current); }


      // operator!=
      //    - parameters : origVal - another reverse iterator
      //    - return type : boolean integer
      //    - returns 1 if this reverse iterator and the parameter
      //       iterator do NOT point to the same location, 0 else.
      int operator!=(const const_reverse_iterator& origVal) const
          { return (current != origVal.current); }


      // operator*
      //    - return type : reference to a node value
      //    - returns the value pointed to by this reverse iterator
      const pair<Ktype, Etype>& operator*() 
      { 
         const_iterator temp = current;
         return *(--temp); 
      }

      // operator->
      //    - return type : reference to a node value
      //    - returns the address of the value in the node
      //         pointed to by this reverse iterator
      const pair<Ktype, Etype>* operator->()  { return &(operator*()); }


      // operator++ (prefix)
      //    - return type : a reverse iterator
      //    - moves the iterator to the next value in the
      //        reverse sequence. If you are at the final, "null"
      //        element, an error message is printed instead
      //        since there is no element to move to. 
      const_reverse_iterator& operator++() { --current; return *this; }

      // operator++ (postfix)
      //    - return type : a reverse iterator
      //    - postfix version of operator++
      const_reverse_iterator operator++(int)
      {
         const_reverse_iterator temp = *this;
         --current;
         return temp;
      }


      // operator-- (prefix)
      //    - return type : a reverse iterator
      //    - moves the iterator to the previous value in the
      //        reverse sequence. If you are at the first 
      //        element, an error message is printed instead
      //        since there is no element to move to. 
      const_reverse_iterator& operator--() { ++current; return *this; }



      // operator-- (postfix)
      //    - return type : a reverse iterator
      //    - postfix version of operator--
      const_reverse_iterator operator--(int)
      {
         const_reverse_iterator temp = *this;
         ++current;
         return temp;
      }


   private:

      // this line lets avl_tree functions use the constructor below
      friend class avl_tree<Ktype, Etype>;


      const_iterator current;    // A reverse_iterator is just
                                 // a special interface wrapper
                                 // around a "forward iterator".


      // const_reverse_iterator
      //    - constructor
      //    - parameters : assignPtr - pointer to store in this
      //                       iterator
      //    - initializes iterator to point to same node as
      //        assignPtr. This function must be private to
      //        protect encapsulation. Right now, clients can
      //        only set iterators to other iterators; if this
      //        function were public, they could set iterators
      //        to any address, thereby breaking the protective
      //        wrapper of encapsulation around the iterator's 
      //        member data (its internal pointer).
      const_reverse_iterator(const_iterator x) : current(x) {}
   };







   // *****************************************
   // *                                       *
   // *  Section 3: avl_tree public functions *
   // *    constructors, etc.                 *
   // *    iterator functions                 *
   // *    collection-editing functions       *   
   // *    information retrieval functions    *
   // *                                       *
   // *****************************************


  // ****************** constructors, etc. 


   // avl_tree
   //    - default constructor 
   //    - initializes tree to be empty
   avl_tree(); 



   // avl_tree
   //    - copy constructor
   //    - parameters : origVal - previously allocated avl_tree object
   //    - initializes object to be a copy of origVal
   avl_tree(const avl_tree& origVal); 



   // There is a third constructor that is supposed to exist,
   // which initializes the AVL tree to hold a particular rage
   // of values, but it requires that a member function be a 
   // template and the compiler doesn't quite like that yet. 


   // ~avl_tree
   //    - destructor
   //    - deletes dynamically allocated memory
   ~avl_tree(); 



   // operator= 
   //    - parameters : origVal - previously allocated avl_tree object
   //    - return value - const reference to this object
   //    - sets object to be a copy of origVal
   const avl_tree& operator=(const avl_tree& origVal);


   // There is an additional means of assigning, where a range
   // of values is passed in and the AVL tree is assigned to that,
   // but it requires that a member function be a template and
   // the compiler doesn't like that quite yet. 


 // **************** iterator functions


   // begin
   //    - return type : iterator
   //    - returns iterator to first location in container 
   iterator begin();


   // begin
   //    - return type : const_iterator
   //    - returns const_iterator to first location in container
   const_iterator begin() const;


   // end
   //    - return type: iterator
   //    - returns iterator to "one past the end" container location
   iterator end();


   // end
   //    - return type: const_iterator
   //    - returns const_iterator to "one past the end" container location
   const_iterator end() const;


   // rbegin
   //    - return type : reverse iterator
   //    - returns reverse iterator to first reverse 
   //              location in container
   reverse_iterator rbegin();


   // rbegin
   //    - return type : constant reverse iterator
   //    - returns constant reverse iterator to first reverse
   //              location in container
   const_reverse_iterator rbegin() const;


   // rend
   //    - return type: reverse iterator
   //    - returns reverse iterator to "just after container" 
   //           reverse location
   reverse_iterator rend();


   // rend
   //    - return type: constant reverse iterator
   //    - returns constant reverse iterator to "just after container"
   //           reverse location
   const_reverse_iterator rend() const;

   


 // ********** collection-editing functions


   // insert
   //    - parameters : insElem - value to be inserted
   //    - return value : a pair that contains an iterator to
   //                      the tree element with the same key as
   //                      our attempted insert value, and a boolean
   //                      integer telling us if the insertion
   //                      was performed (1) or if we instead
   //                      were trying to insert a duplicate key
   //                      and thus stopped and returned an iterator
   //                      to the already existing type
   //    - inserts insElem into tree (does nothing if key is
   //         already there
   pair<iterator, int> insert(const pair<Ktype, Etype>& insElem);

  
   // insert
   //    - parameters : position - an iterator indicating the 
   //                     position where we'd want to insert our 
   //                     value
   //                 : insElem - value to be inserted
   //    - return value : a pair that contains an iterator to
   //                      the tree element with the same key as
   //                      our attempted insert value, and a boolean
   //                      integer telling us if the insertion
   //                      was performed (1) or if we instead
   //                      were trying to insert a duplicate key
   //                      and thus stopped and returned an iterator
   //                      to the already existing type
   //    - inserts insElem into tree (does nothing if key is
   //         already there). The iterator position is supposed
   //         to provide us with an insertion "hint" to improve
   //         performance; from the standpoint of the actual effects
   //         of the function, this function is exactly the same 
   //         as the previous insert. So, right now, we have not
   //         implemented the "hint" feature, and this function
   //         simply calls the previous insert and at least gets
   //         things correct, if not as efficient as possible. 
   iterator insert(iterator position, const pair<Ktype, Etype>& insElem);


   // There is a third insert algorithm that is supposed to exist,
   // which initializes the AVL tree to hold a particular rage
   // of values, but it requires that a member function be a
   // template and the compiler doesn't quite like that yet.


   // erase
   //    - parameters : position - iterator to a particular value
   //    - remove the value indicated by position
   void erase(iterator position);



   // erase
   //    - parameters : eraseKey - the key of the value we wish to erase
   //    - return value : boolean integer
   //    - remove the value with key eraseKey, if such a value exists
   //         in the tree. Return 1 if you performed a removal, 0 else. 
   int erase(const Ktype& eraseKey);



   // erase
   //    - parameters : first - an iterator to the start of a range
   //                              in this tree
   //                 : last - the end iterator for a range in this 
   //                             tree
   //    - remove the values in the range [first,last)
   void erase(iterator first, iterator last);



   // clear
   //    - clears the tree, same as "erase(begin(), end());". 
   //       Uncertain whether this is still part of the STL standard
   //       or not, but Stroustrup's text lists it, so we've got it
   //       here as well. 
   void clear();



 // ********************* information retrieval functions


   // find
   //    - parameters : searchKey - key we are searching for 
   //    - return value : an iterator 
   //    - if key is part of a node value pair in tree, return  
   //         an iterator to that node. Otherwise, return end();   
   iterator find(const Ktype& searchKey);



   // find
   //    - parameters : searchKey - key we are searching for
   //    - return value : a constant iterator
   //    - if key is part of a node value pair in tree, return
   //         a constant iterator to that node. Otherwise, return end();   
   const_iterator find(const Ktype& searchKey) const;



   // count
   //    - parameters : searchKey - key we are searching for
   //    - return value : boolean integer
   //    - returns 1 if key is part of a node value pair in 
   //          tree, 0 else. NOTE - this is sort of a
   //          silly function if you know for sure you have
   //          no duplicate keys, but not every STL container
   //          class has that restriction, so this function
   //          is included in all those classes. 
   int count(const Ktype& searchKey) const;



   // lower_bound
   //    - parameters : searchKey - key we are searching for
   //    - return value : an iterator
   //    - if key is part of a node value pair in tree, return
   //         an iterator to the first node with that searchKey
   //         as key. Otherwise, return end(). NOTE - this is sort of 
   //          a silly addition if you know for sure you have
   //          no duplicate keys, since it's the same as find(), but 
   //          not every STL container class has that restriction, so 
   //          this function is included in all those classes, and
   //          is just written to do nothing new in classes like
   //          map and this avl_tree class that implements it. 
   iterator lower_bound(const Ktype& searchKey);



   // lower_bound
   //    - parameters : searchKey - key we are searching for
   //    - return value : an const_iterator
   //    - if key is part of a node value pair in tree, return
   //         an iterator to the first node with that searchKey
   //         as key. Otherwise, return end(). NOTE - this is sort of
   //          a silly addition if you know for sure you have
   //          no duplicate keys, since it's the same as find(), but 
   //          not every STL container class has that restriction, so 
   //          this function is included in all those classes, and
   //          is just written to do nothing new in classes like
   //          map and this avl_tree class that implements it. 
   const_iterator lower_bound(const Ktype& searchKey) const;




   // upper_bound
   //    - parameters : searchKey - key we are searching for
   //    - return value : an iterator
   //         return an iterator to the first node with key greater
   //         than searchKey. If there is no such node, return end(). 
   iterator upper_bound(const Ktype& searchKey);



   // upper_bound
   //    - parameters : searchKey - key we are searching for
   //    - return value : a constant iterator
   //         return a constant iterator to the first node with key greater
   //         than searchKey. If there is no such node, return end().
   const_iterator upper_bound(const Ktype& searchKey) const;



   // equal_range
   //    - parameters : searchKey - key we are searching for
   //    - return value : a pair of iterators
   //    - return (1) the iterator which points to searchKey's node, 
   //        and (2) the iterator which points to the key after
   //        searchKey. Note that in a class where you could have
   //        duplicate keys, you'd be defining a range with that
   //        return type; here, you are simply returning iterators
   //        to two consecutive spots in the container, since we
   //        have no duplicate keys.
   pair<iterator, iterator> equal_range(const Ktype& searchKey);



   // equal_range
   //    - parameters : searchKey - key we are searching for
   //    - return value : a pair of constant iterators
   //    - return (1) the iterator which points to searchKey's node,
   //        and (2) the iterator which points to the key after
   //        searchKey. Note that in a class where you could have
   //        duplicate keys, you'd be defining a range with that
   //        return type; here, you are simply returning iterators
   //        to two consecutive spots in the container, since we
   //        have no duplicate keys.
   pair<const_iterator, const_iterator> 
                          equal_range(const Ktype& searchKey) const;




   // empty
   //    - return value : boolean integer
   //    - returns 1 if tree is empty, 0 otherwise
   int empty() const
        { return (headerNode->parent == NULL); }


   // size
   //    - return value : size of tree
   //    - returns number of elements in tree
   int size() const
        { return treeSize;}



   // Typical associative container functions we have not implemented:
   //
   // max_size() - would return size of largest possible container,
   //              we are doing nothing that would possibly reach the
   //              maximum allowed size, so we're not going to worry
   //              about it here
   // key_comp()  
   //   and value_comp() - we've left these two out for the same 
   //                      reason we didn't have typedefs for 
   //                      key_compare and value_compare, namely, that
   //                      we're not going to further complicate
   //                      things by allowing comparisons other than <
   //                      on keys
   // get_allocator() - again, just as we didn't bother with 
   //                   "allocator"-related typedefs, we're not bothering
   //                   with this "allocator"-related function
   //
   // operator< and operator== and operator[]
   // 
   // swap()
 

   // ****************************************************************
   // *                                                              *
   // *  Section 4: avl_tree private types, variables, and functions *
   // *    constructors, etc.                                        *
   // *    iterator functions                                        *
   // *    collection-editing functions                              *
   // *    information retrieval functions                           *
   // *                                                              *
   // ****************************************************************
 
 

// ************ AVL private member variables and functions
// 
//  - The implementation of our AVL tree will be as follows:
//      - regular idea of a node, with left and right children
//           and an element field. Plus, since it is an AVL tree,
//           we need to store the height.
//      - however, the node will also have a parent pointer which 
//           will point to the node's parent in the tree
//      - in addition to the nodes making up the tree, there will
//           be a "header node". The AVL tree does not have a root
//           pointer; it has a header node pointer, and so all access
//           to the tree begins at the header node. The header node
//           will point to the root (we'll use the "parent" field to
//           do this, because we need a pointer and that one won't
//           be used for anything else), and will also point to the 
//           leftmost and rightmost elements of the tree. In an empty
//           tree, the left and right pointers of the header node
//           both point to NULL.
//      - this header node will also serve as the implementation of 
//           the "position after the end of the container"; that
//           is, the function call end() will return an iterator
//           which points to the header node
//      - the root's parent pointer will point to the header node;
//           among other things, this will make iteration convenient
//           as our iteration algorithm will naturally end up trying 
//           to access the root's parent if we attempt a ++ from the
//           rightmost element
//      - when we remove a node from *any* container, the iterators
//           to that container position are now invalid. We expect
//           this. However, the iterators to other container positions
//           should not be affected. However, when we remove a value
//           which has two children, we always did this by writing
//           the inorder successor into value's node and deleting the
//           inorder successor's node. This means the address of the
//           inorder successor changes and iterators that used to 
//           point to it won't point to it anymore. We don't want this.
//           So, for this reason, we will actually disengage the
//           node rather than performing a copy -- that is, since 
//           value has two children, we don't want to eliminate that
//           node *position*, so we will carefully save the two children,
//           and the parent, and then eliminate value's node, and finally
//           we will write the IOS's node (which we find and "delete" 
//           further down in the tree) into this spot by pointing its
//           left, right, and parent pointers to the saved left and
//           right children and saved parent of the previously-deleted
//           "value" node. So, we are still writing the IOS into value's
//           position in the tree rather than completely restructuring 
//           the tree, but we do this in such a manner that even though
//           the IOS now has different chilren than before, the address
//           of IOS's node remains the same. 
//      - it is partly due to this change to the remove implementation
//           that we do not use a threaded tree (see page 121 of Lewis
//           and Denenburg). Such a threaded tree would be handy for
//           iteration, since for about half the nodes we could access
//           the IOS (i.e. ++) or IOP (i.e. --) in one operation. 
//           However, our slight change to the remove implementaiton
//           means thread maintenance will be more difficult and 
//           ultimately might cost us more time than it saves us in
//           real usage. So, for now we'll keep it simlple. 
//
//


private:

   // friend declarations to make sure the iterators can
   //  access the avl_tree_node class
   friend class iterator;
   friend class const_iterator;


   // *********************************************
   // *                                           *
   // *  avl_tree<>::avl_tree_node                *
   // *                                           *
   // *  The node class for our AVL tree.         * 
   // *                                           *
   // *********************************************

   class avl_tree_node
   {
   public:   // public within scope of avl_tree implementation.
             //  not within global scope

      // avl_tree_node
      //    - default constructor
      //    - initializes node to default values
      avl_tree_node() : element(), left(NULL), right(NULL),
                               parent(NULL), height(0) {}


      // avl_tree_node
      //    - constructor
      //    - parameters : elmt - initialization element
      //                 : leftPtr - initialization left pointer
      //                 : rightPtr - initialization right pointer
      //                 : hgt - initialization of height
      //    - initializes node to parameter values
      avl_tree_node(pair<Ktype, Etype> elmt, avl_tree_node* leftPtr = NULL,
              avl_tree_node* rightPtr = NULL, avl_tree_node* parentPtr = NULL,
                             int hgt = 0) :
            element(elmt), left(leftPtr), right(rightPtr),
                                parent(), height(hgt) {}

      pair<Ktype, Etype> element;    // value element of node 
      avl_tree_node* left;           // pointer to left subtree
      avl_tree_node* right;          // pointer to right subtree
      avl_tree_node* parent;         // pointer to parent;
      int height;                    // height of node

   };   // end avl_tree_node class


   // ************** Member data for AVL tree
   // **************

   avl_tree_node* headerNode;        // pointer to header node
   int treeSize;                     // number of nodes in tree



   // ************** Node access functions 
   // **************


   // root
   //    - return type : a reference to an AVL node pointer
   //    - our header node's parent pointer will point to the
   //        root. Abstractly, the header is pointing to the
   //        root with a "to the root" pointer, but our AVL node
   //        happens to have a parent pointer that would otherwise
   //        be NULL for the header node, so we'll use that parent
   //        pointer here instead of adding a fourth, "to the
   //        root" pointer to the AVL node just for this one case.
   //        By returning a reference we can type expressions
   //        such as Root() = new avl_tree_node() and use Root()
   //        just like an actual root pointer.
   avl_tree_node*& root() const  { return headerNode->parent;  }


   // leftmost
   //    - return type : an AVL node pointer 
   //    - returns a pointer to the leftmost element in the
   //        tree. There is no need to return by reference
   //        here, since we don't generally have a "leftmost"
   //        pointer in a tree class, unlike a "root" pointer
   //        which we definitely needed.
   avl_tree_node* leftmost() const { return headerNode->left; }


   // rightmost
   //    - return type : an AVL node pointer 
   //    - returns a pointer to the rightmost element in the
   //        tree. There is no need to return by reference
   //        here, since we don't generally have a "rightmost"
   //        pointer in a tree class, unlike a "root" pointer
   //        which we definitely needed.
   avl_tree_node* rightmost() const { return headerNode->right; }


   // key
   //    - parameters : thisNode - a node we want the key of
   //    - return type : a key value
   //    - thisNode stores a (Key, Info) pair. This function 
   //       will extract the key from this pair and return it. 
   //       We can do this because we know that map class using
   //       this class passes in a pair object, so we know that 
   //       Valtype has a public "first" field we can access. 
   //       In the real STL, we can pass in a KeyExtraction function,
   //       but that is too complicated for us for now, so instead
   //       we will assume our Valtype is a pair<> just as in our
   //       generalized global functions we assume the generic type
   //       iterator is indeed an iterator type with access to ++ 
   //       and * and so on.  
   Ktype key(const avl_tree_node* thisNode) const 
                    {return (thisNode->element).first;}


   // Key
   //    - parameters : value - a value pair we want the key of
   //    - return type : a key value
   //    - thisNode stores a (Key, Info) pair. This function
   //       will extract the key from this pair and return it.
   //       We can do this because we know that map class using
   //       this class passes in a pair object, so we know that
   //       Valtype has a public "first" field we can access.
   //       In the real STL, we can pass in a KeyExtraction function,
   //       but that is too complicated for us for now, so instead
   //       we will assume our Valtype is a pair<> just as in our
   //       generalized global functions we assume the generic type
   //       iterator is indeed an iterator type with access to ++
   //       and * and so on.
   Ktype key(const pair<Ktype, Etype> value) const { return value.first;}




 // ************* Binary search tree functions

   // copy
   //    - parameters : TN - a treenode pointer
   //    - return value : a treenode pointer
   //    - makes a new treenode which is a copy of the
   //        parameter node -- including subtrees -- and returns it
   avl_tree_node* copy(const avl_tree_node* TN);


   // clear
   //    - parameters : TN - reference to a treenode pointer
   //    - recursively clears the tree
   void clear( avl_tree_node*& TN);



   // insert
   //    - parameters : insElem - element to be inserted
   //                 : TN - a treenode pointer
   //                 : parentOfTN - the parent of the node *TN 
   //    - return type : an iterator to the newly inserted element
   //    - recursively inserts insElem into tree (does nothing if
   //         it is already there), and corrects balances
   iterator insert(const pair<Ktype, Etype>& insElem, avl_tree_node*& TN,
                                        avl_tree_node* parentOfTN);


   // remove
   //    - parameters : remElem - element to be removed
   //                 : TN - a treenode pointer
   //    - recursively removes remElem from tree if it is in tree
   //         and corrects balances
   void remove(const pair<Ktype, Etype>& remElem, avl_tree_node*& TN,
                                  avl_tree_node* parentOfTN);




   // find
   //    - parameters : searchElem - element to be found
   //                 : TN - a treenode pointer
   //    - return value : treenode pointer
   //    - returns 1 if searchElem is found in tree, 0 else
   //        also, if found, returns pointer to that node
   avl_tree_node* find(const pair<Ktype, Etype>& searchElem, avl_tree_node* TN) const;


/*
   // Find_Min
   //    - parameters : TN - a treenode pointer
   //    - return value : treenode pointer
   //    - returns pointer to the minimum value in tree
   void* Find_Min(avl_tree_node* TN) const;



   // Find_Max
   //    - parameters : TN - a treenode pointer
   //    - return value : treenode pointer
   //    - returns pointer to the maximum value in tree
   void* Find_Max(avl_tree_node* TN) const;

*/


 // ***************   Additional AVL-specific Helper Functions

   // node_height
   //    - parameters : TN - a treenode pointer    
   //    - return value : integer height of node
   //    - returns node's height; returns -1 if pointer is NULL
   int node_height(avl_tree_node* TN);


   // calculate_height
   //    - parameters : TN - a treenode pointer 
   //    - correctly sets TN's height; assumes correct
   //        subtree heights
   void calculate_height(avl_tree_node* TN);


   // single_right_rotation
   //    - parameters : k2 - root of subtree
   //    - performs a rotation between a node (k2) and its
   //         left child, updating the heights of both.
   //         Can be called only if k2 has a left child.
   void single_right_rotation(avl_tree_node*& k2);


   // double_right_rotation
   //   Performs a left-right rotation, also known as a
   //    double right rotation.  Can only be called if k3
   //    has a left child and k3's left child has a right
   //    child.
   void double_right_rotation(avl_tree_node*& k3);


   // single_left_rotation
   //   Performs a rotation between a node (k2) and its
   //    right child, updating the heights of both.
   //   Can be called only if k2 has a right child.
   void single_left_rotation(avl_tree_node*& k2);


   // double_left_rotation
   //   Performs a right-left rotation, also known as a
   //    double left rotation.  Can only be called if k3
   //    has a right child and k3's right child has a left
   //    child.
   void double_left_rotation(avl_tree_node*& k3);

};


#endif



