#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/abc350/submissions/52600656
// 

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef vector<int> vi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
const ll mod = 998244353;
int n,q;

struct Empty {};
namespace splay_tree {
/** @brief Implements a splay tree*/
template <typename Node> struct PathParent { Node *path_parent{}; };
template <typename T, bool has_link_cut = false>
struct SplayNode
    : public conditional_t<has_link_cut, PathParent<SplayNode<T, has_link_cut>>, Empty> {
      public:
	SplayNode() {}
	SplayNode(T value_arg) : value{value_arg} {}
	T value{};		       //!< Value associated with node
	array<SplayNode *, 2> child{}; //!< Left and right children
	SplayNode *parent{};	       //!< Pointer to parent
	bool side() const {
		/*! Returns true if child is on the right, and false otherwise*/
		return parent->child[1] == this;
	}
	void rotate() {
		/*! Rotate node x around its parent */
		const auto p = parent;
		const bool i = side();

		if (p->parent) {
			p->parent->attach(p->side(), this);
		} else {
			parent = nullptr;
		}
		p->attach(i, child[!i]);
		attach(!i, p);
		if constexpr (has_link_cut) {
			this->path_parent = p->path_parent;
		}
	}
	void splay() {
		/*! Splay node x. x will become the root of the tree*/
		for (; parent; rotate()) {
			if (parent->parent) {
				(side() == parent->side() ? parent : this)->rotate();
			}
		}
	}
	array<SplayNode *, 2> split() {
		splay();
		// TODO use detach function
		const auto right = child[1];
		if (right) {
			right->parent = nullptr;
		}
		this->right = nullptr;
		return {this, right};
	}
	void attach(bool side, SplayNode *const new_) {
		/*! Attach node new_ as the node's side children*/
		if (new_) {
			new_->parent = this;
		}
		child[side] = new_;
	}
};
}
using namespace splay_tree;

namespace link_cut {
using Node = SplayNode<ll, true>;
Node *make_tree() {
	/*! Make a new tree */
	return new Node{};
}
void detach_child(Node *node) {
	/*! Converts node's preferred child edge to a path parent edge*/
	if (node->child[1]) {
		node->child[1]->path_parent = node;
		node->child[1]->parent = nullptr;
	}
}
Node *access(Node *node) {
	/*! Moves node to the root of the auxillary tree containing the root node of the tree.
	 * Returns last path-parent of node as it moves up the tree*/
	node->splay();
	detach_child(node);
	node->child[1] = nullptr;
	Node *par = node;
	while (node->path_parent) {
		par = node->path_parent;
		par->splay();
		detach_child(par);
		par->attach(1, node);
		node->path_parent = nullptr;
		node->splay();
	}
	return par;
}
Node *find_root(Node *node) {
	/** Finds the root of the tree containing node*/
	access(node);
	for (; node->child[0]; node = node->child[0])
		;
	access(node);
	return node;
}
void cut(Node *node) {
	/*! Detaches the subtree of node from the tree of node's parent*/
	access(node);
	node->child[0]->parent = nullptr;
	node->child[0] = nullptr;
}
void link(Node *par, Node *child) {
	/*! Makes child the child of par*/
	access(child);
	access(par);
	child->attach(0, par);
}
Node *lca(Node *u, Node *v) {
	/*! Returns lowest common ancestor of nodes u and v or nullptr if u and v are in different
	 * trees*/
	if (find_root(u) != find_root(v)) {
		return nullptr;
	}
	access(u);
	return access(v);
}
} // namespace link_cut
using namespace link_cut;

void solve() {
    cin >>n >> q;
    vector<int> ans;
    ans.push_back(0);
    vector<Node*> v;
    rep(i,0,n+1) {
        Node* now = new Node(i);
        v.push_back(now);
    }
    while(q--) {
        int a,b,c; cin >>a >>b >>c;
        a = 1+ ((1ll*a*(1+ans.back()))%mod)%2;
        b = 1 + ((1ll*b*(1+ans.back())%mod))%n;
        c = 1 + (1ll*c*(1+ans.back())%mod)%n;
        cout <<a <<b <<c <<endl;
        if(a==1) {
            link(v[b],v[c]);
        } else {
            // cout <<"lca " <<lca(v[b],v[c])->value <<endl;
            bool ok = 0;
            auto c1 = v[c];
            rep(i,0,2) {
                auto c2 = c1->path_parent;
                if(!c2) {
                    break;
                }
                cout <<"c2 " <<c2->value <<endl;
                cout <<"c2 par " <<c2->parent->value <<endl;
                if(i==1 && c2->value==b) {
                    ok = 1;
                }
                c1 = c2;
            }
            if(ok) {
                auto c2 = v[c]->path_parent;
                ans.push_back(c2->value);
                continue;
            }
            auto b1 = v[b];
            rep(i,0,2) {
                auto b2 = b1->path_parent;
                if(!b2) {
                    break;
                }
                cout <<"b2 " <<b2->value <<endl;
                cout <<"b2 par " <<b2->parent->value <<endl;
                if(i==1 && b2->value==c) {
                    ok = 1;
                }
                b1 = b2;
            }
            if(ok) {
                auto b2 = v[b]->path_parent;
                ans.push_back(b2->value);
                continue;
            }
            b1 = v[b]->path_parent; c1 = v[c]->path_parent;
            cout <<(b1?b1->value:0) <<" " <<(c1?c1->value:0) <<endl;
            if(b1 && c1 && b1->value==c1->value) {
                ans.push_back(b1->value);
            }  else {
                ans.push_back(0);
            }
        }
    }
    rep(i,1,sz(ans)) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}