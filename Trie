	struct TrieNode{
		TrieNode*chil[26];              //array
		TrieNode()
		{
			for(int i=0;i<26;i++)
			{
				child[i]=NULL;
			}
		}
	}

class Trie{
		TrieNode* root;
	public:
		Trie()
		{
				root=new TrieNode();
		}
		void insert(string& s)
		{
			TrieNode* node=root;
			for(int i=0;i<s.size();i++)
			{
				char check=s[i];
				if(node->child[check-'a']==NULL)
					node->child[check-'a']=new TrieNode();
				node=node->child[check-'a'];

			}
		}
};

//main()
	//	Trie t;         //object
		//t.insert(strings....)
