#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct tree_node
{
    int weight;
    int l_distance;
    int r_distance;
    tree_node* left_node;
    tree_node* right_node;
};

struct tree_node* NewNode(int weight = 0){
    struct tree_node* new_node = new(tree_node);
    new_node->weight = weight;
    new_node->l_distance = 0;
    new_node->r_distance = 0;
    new_node->left_node = NULL;
    new_node->right_node = NULL;
    return new_node;
}

vector<tree_node*> tree_vec;

tree_node *read_line(int depth)
{
    int left_weight; cin >> left_weight;
    int left_distance; cin >> left_distance;
    int right_weight; cin >> right_weight;
    int right_distance; cin >> right_distance;
    // cout << left_weight << " " << left_distance << " " << right_weight << " " << right_distance << endl;
    tree_node *new_node = NewNode();
    // Break condition 
    if (left_distance == 0 && left_weight == 0 && right_weight == 0 && right_distance == 0){
        new_node->weight = -1;
        return new_node;
    }
    new_node->l_distance = left_distance;
    new_node->r_distance = right_distance;
    new_node->weight = 0;
    if (left_weight == 0){
        new_node->left_node = read_line(depth + 1);
        // cout << new_node->left_node->left_node->weight << endl;
    }else{
        new_node->left_node = NewNode(left_weight);
    }
    
    if (right_weight == 0){
        new_node->right_node = read_line(depth + 1);
    }else{
        new_node->right_node = NewNode(right_weight);
    }
    if (depth == 0){
        tree_vec.push_back(new_node);
    }
    return new_node;
};

// Function that returns the weight of the branch if every child is balanced, and -1 if not
long long int check_if_balanced(tree_node* node){
    if ((*node).weight != 0){
        return (*node).weight;
    }
    long long int left_weight = check_if_balanced((*node).left_node);
    // cout << left_weight*(*node).l_distance << endl;
    long long int right_weight = check_if_balanced((*node).right_node);
    // cout << right_weight << endl;
    if (left_weight >= 0 && right_weight >= 0 && left_weight*(*node).l_distance == right_weight*(*node).r_distance){
        return left_weight + right_weight;
    }else{
        return -1 ;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tree_node *new_node = read_line(0);
    while ((*new_node).weight != -1)
    {
        new_node = read_line(0);
    }
    // cout << (*(*tree_vec[0].left_node).left_node).weight << endl;
    for (auto root_node : tree_vec) {
        long long tree_weight = check_if_balanced(root_node);
        if (tree_weight != -1){
            cout << "SI\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
