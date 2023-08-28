//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        vector<int>v,a;
        while(head){
            v.push_back(head->data);
            head = head->next;
        }
        
        int n = v.size();
        priority_queue<int>pq;
        for(int i = n-1;i>=0;i--){
            if(pq.empty()){
                pq.push(v[i]);
                a.push_back(v[i]);
                continue;
            }
            if(v[i]<pq.top()){
              continue;   
            }
            a.push_back(v[i]);
            pq.push(v[i]);
        }
        reverse(a.begin(),a.end());
        Node *head1 = new Node(0);
        Node *t = head1;
        for(auto &it : a){
            Node* temp = new Node(it);
            t->next = temp;
            t = t->next;
        }
        return head1->next;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends