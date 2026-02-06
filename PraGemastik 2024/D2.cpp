#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int oo = INT_MAX;
const int MOD  = int( 1e9 )+7;

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// Structure representing a treap node
struct node {
  int key;
  int priority;
  int cnt;
  ll sum;
  ll assign;
  ll add;
  node *left, *right;
  node( int key ) : key( key ), priority( rand()%MOD ),
                    cnt( 1 ), sum( key ), assign( -1 ), add( 0 ),
                    left( NULL ), right( NULL ) {}
};

typedef node* pnode;

//Gets the amount of nodes that the subtree starting at root has
int cnt( pnode &root ) {
  if( !root ) {
    return 0;
  }
  return root->cnt;
}

//Updates the amount of nodes that the subtree starting at root has
void upd_cnt( pnode &root ) {
  if( root ) {
    root->cnt = 1 + cnt( root->left ) + cnt( root->right );
  }
}

//Gets the minimum of the keys that subtree starting at root has
int sum( pnode &root ) {
  if( !root ) {
    return oo;
  }
  return root->sum;
}

//Updates the minimum of the keys that subtree starting at root has
// void upd_minimum( pnode &root ) {
//   if( root ) {
//     root->minimum = min( root->key, min( minimum( root->left ), minimum( root->right ) ) );
//   }
// }

void upd_sum( pnode &root ) {
  if( root ) {
    root->sum = root->key + sum( root->left ) + sum( root->right );
  }
}

//Lazy propagation for the reverse operation
// void push( pnode &root ) {
//   if( root && root->rvs ) {
//     root->rvs = false;
//     swap( root->left, root->right );
//     if( root->left != NULL ) root->left->rvs ^= true;
//     if( root->right != NULL ) root->right->rvs ^= true;
//   }
// }

void push_assign( pnode &root ) {
  if( root && root->assign != -1 ) {
    root->key = root->assign;
    root->sum = root->cnt * root->key;
    if( root->left != NULL ) root->left->assign = root->assign;
    if( root->right != NULL ) root->right->assign = root->assign;
    root->assign = -1;
  }
}

void push_add( pnode &root ) {
  if( root && root->add != 0 ) {
    root->key += root->add;
    root->sum += root->cnt * root->add;
    if( root->left != NULL ) root->left->add += root->add;
    if( root->right != NULL ) root->right->add += root->add;
    root->add = 0;
  }
}

/*
 * Combines two subtrees T1 and T2 and returns the new tree(root).
 * This operation has O(logN) complexity.
 * It works under the assumption that T1 and T2 are ordered (all keys in T1 are smaller than keys in T2).
*/
void merge( pnode &root, pnode T1, pnode T2 ) {
//   push( T1 ); push( T2 );
    push_assign( T1 ); push_assign( T2 );
    push_add( T1 ); push_add( T2 );
    if( !T1 || !T2 ) {
        root = T1 ? T1 : T2 ;
        return;
    }
    if( T1->priority > T2->priority ) {
        merge( T1->right, T1->right, T2 );
        root = T1;
    }
    else {
        merge( T2->left, T1, T2->left );
        root = T2;
    }
    upd_cnt( root );
    upd_sum( root );
}

/*
 * Separates tree root in 2 subtrees left and right trees (which are the return values of split)
 * so that left contains all elements with key XL<k, and R contains all elements with key XR>k.
 * This operation has O(logN) complexity.
*/
void split( pnode root, int k, pnode &left, pnode &right, int add = 0 ) {
    if( !root ) {
        left = right = NULL;
        return;
    }
//   push( root );
    push_assign( root );
    push_add( root );
    int cur_key = add + cnt( root->left );
    if( cur_key < k ) {
        split( root->right, k, root->right, right, add + 1 + cnt( root->left ) );
        left = root;
    }
    else {
        split( root->left, k, left, root->left, add );
        right = root;
    }
    upd_cnt( root );
    // upd_minimum( root );
    upd_sum( root );
}

//This operation inserts a node with key = k to the treap
void insert( pnode &root, int idx, int k ) {
    pnode new_node = new node( k );
    if( !root ) {
        root = new_node;
        return;
    }
    pnode left, right;
    split( root, idx, left, right );
    merge( left, left, new_node );
    merge( root, left, right );
    upd_cnt( root );
//   upd_minimum( root );
    upd_sum( root );
}

//This operation erases the node with key = k to the treap
void erase( pnode &root, int k ) {
    if( !root ) {
        return;
    }
    // push( root );
    push_assign( root );
    push_add( root );
    if( root->key == k ) {
        merge( root, root->left, root->right );
    }
    else if( root->key < k ) {
        erase( root->right, k );
    }
    else {
        erase( root->left, k );
    }
    upd_cnt( root );
//   upd_minimum( root );
    upd_sum( root );
}

// void preorder(node* root) {
//   if (root) {
//     cout << root->key << " ";
//     preorder(root->left);
//     preorder(root->right);
//   }
// }

// // Free the allocated memory
// void delete_treap(node* root) {
//   if (root) {
//     delete_treap(root->left);
//     delete_treap(root->right);
//     delete root;
//   }
// }

//In T3 is the tree with the values [a,b]
// int minimum_query( node *root, int a, int b ) {
//   pnode T1, T2, T3;
//   split (root, a, T1, T2);
//   split (T2, b-a+1, T2, T3);
//   int mn = minimum(T2);
//   merge(root, T1, T2);
//   merge(root, root, T3);
//   return mn;
// }

int sum_query( node *root, int a, int b ) {
  pnode T1, T2, T3;
  split (root, a, T1, T2);
  split (T2, b-a+1, T2, T3);
  int sm = sum(T2);
  merge(root, T1, T2);
  merge(root, root, T3);
  return sm;
}

int point_query( node *root, int a ) {
  pnode T1, T2;
  split (root, a, T1, T2);
  int ans = T2->key;
  merge(root, T1, T2);
  return ans;
}

int add_all_query( node *root, int a, int b, int x ) {
  pnode T1, T2, T3;
  split (root, a, T1, T2);
  split (T2, b-a+1, T2, T3);
  T2->add += x;
  merge(root, T1, T2);
  merge(root, root, T3);
}

int assign_all_query( node *root, int a, int b, int x ) {
  pnode T1, T2, T3;
  split (root, a, T1, T2);
  split (T2, b-a+1, T2, T3);
  T2->assign = x;
  merge(root, T1, T2);
  merge(root, root, T3);
}

//In T3 is the tree with the values [a,b]
// void reverse_query( node *root, int a, int b ) {
//   pnode T1, T2, T3;
//   split (root, a, T1, T2);
//   split (T2, b-a+1, T2, T3);
//   T2->rvs = true;
//   merge(root, T1, T2);
//   merge(root, root, T3);
// }

int main( ) {
    int N, Q;
    cin >> N;

    pnode root = NULL;
    multiset<int> s;
    ordered_set os;
    for( int i = 0; i < N; i++ ) {
        int x;
        cin >> x;
        s.insert( x );
        os.insert( {x, i} );
    }
    cin >>Q;
    int i = 0;
    for( int x : s ) {
        insert( root, i, x );
        i++;
    }

    int choice;
    int key, a, b, sz = 0;
    int value;
    int j = N;
    while (Q--) {
        // cout << " 1.Insert\n 2.Erase\n 3.Get min in range\n 4.Reverse range\n 5.Preorder\n 6.Quit\n";
        cin >> choice;
        if (choice == 1) {
            // cout << "Enter key : ";
            cin >> value;
            int key = os.order_of_key( {value, j} );
            insert(root, sz++, key);
        }
        else if (choice == 2) {
            cin >> key;
            erase(root, key);
            sz--;
        }
        else if (choice == 3) {
            cin >> key;
            cout << point_query( root, key ) << endl;
            // cout << "Enter range [A,B] (0 indexed): ";
            // cin >> a >> b;
            // if( a > b || b >= sz ) {
            // cout << "A and B must be valid\n";
            // }
            // else {
            // cout << minimum_query( root, a, b );
            // }
            // cout << endl;
        }
        else if (choice == 4) {
            // cout << "Enter range [A,B] (0 indexed): ";
            // cin >> a >> b;
            // if( a > b || b >= sz ) {
            // cout << "A and B must be valid\n";
            // }
            // else {
            // reverse_query( root, a, b );
            // }
            // cout << endl;
            cin >> a >> b;
            cout << sum_query( root, a, b ) << endl;
        }
        else if (choice == 5) {
            // preorder(root);
            // cout << endl;
            // add all
            cin >> value;
            add_all_query( root, 0, sz, value );
        }
        else {
            // break;
            cin >> value;
            key = os.order_of_key( {value, j} );
            assign_all_query( root, 0, sz, key );
        }
        j++;
    }
    // delete_treap(root);
    return 0;
}