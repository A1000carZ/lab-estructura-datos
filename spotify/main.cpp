#include <iostream>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

using namespace std;

struct song {
	string name;
	string author;
	int duration;
	song():name("Prueba"),author("prueba"),duration(0) {}
	song(string name,string author,int duration):name(name),author(author),duration(duration) {}
};

struct Node{
	song value;
    Node *right;
    Node *left;
};

void printPlaylist(Node *node);
Node* playPreviousSong(Node*node);
Node* playNextSong(Node*node);
Node* deleteSong(Node*node,song song);
Node* defaultList();
Node* addSongAtBeginning(Node*Node);
Node* addSongAtEnd(Node*Node);
Node* queuePlayList(Node*node);
Node* favtoritesList(Node*node);
void sortPlaylist(Node*node);



int main() {
    song songToDelete("Stand By Me","John Lennon", 210);
	cout << "Spotify"<<endl;
	Node* head = NULL;
    head = defaultList(); // create a default playlist
	printPlaylist(head);
    //head=deleteSong(head, songToDelete);
    sortPlaylist(head);
    printPlaylist(head);
	return 0;
}

Node *addSongAtBeginning(Node *lastNode)
{
    int value;
    song s;
    cout << "Enter song name: ";
    cin >> s.name;
    cout << "Enter song author: ";
    cin >> s.author;
    cout << "Enter song duration (in seconds): ";
    cin >> s.duration;
    Node *newNode = new (Node);
    newNode->value = s;
    newNode->left = lastNode;
    newNode->right = NULL;
    lastNode->right = newNode;
    lastNode = newNode;
    return lastNode;
}

Node *addSongAtEnd(Node *firstNode)
{
    int value;
    Node *newNode = new (Node);
    song s;
    cout << "Enter song name: ";
    cin >> s.name;
    cout << "Enter song author: ";
    cin >> s.author;
    cout << "Enter song duration (in seconds): ";
    cin >> s.duration;
    newNode->value = s;
    newNode->right = firstNode;
    newNode->left = NULL;
    firstNode->left = NULL;
    firstNode = newNode;

    return firstNode;
}

void printPlaylist(Node *node)
{
    Node *temp;
    temp = node;
    cout << endl
         << "\tEstatus de Playlist" << endl<<endl;
    while (temp != NULL)
    {
        cout <<"\t"<< temp->value.name<<" - "<<temp->value.author<<endl;
        //if (temp->right != NULL)
        //    cout << " 👉 ";
        temp = temp->right;
    }
    cout << endl;
}

Node* playPreviousSong(Node* node) {
    // implement code to play the previous song
    if (node->left == NULL) {
        cout << "No previous song available." << endl;
        return node;
    } else {
        return node->left;
    }
}

Node* playNextSong(Node* node) {
    // implement code to play the next song
    if (node->right == NULL) {
        cout << "End of playlist reached." << endl;
        return node;
    } else {
        return node->right;
    }
}

Node* deleteSong(Node* node, song s) {
    if (node == NULL) {
        return node;
    }
    if (node->value.name == s.name && node->value.author == s.author && node->value.duration == s.duration) {
        // The song to be deleted is the head node
        Node* temp = node->right;
        if (temp != NULL) {
            temp->left = NULL;
        }
        delete node;
        return temp;
    }
    node->right = deleteSong(node->right, s);
    return node;
}

Node* defaultList() {
    song s1("Elephant In The Room","Confetti", 180);
    song s2("Stand By Me","John Lennon", 210);
    song s3("Are You Ready","AC/DC", 240);
    song s4("Cactus","Gustavo Cerati", 270);
    
    Node* node1 = new Node;
    node1->value = s1;
    node1->left = NULL;
    node1->right = NULL;
    
    Node* node2 = new Node;
    node2->value = s2;
    node2->left = node1;
    node2->right = NULL;
    node1->right = node2;
    
    Node* node3 = new Node;
    node3->value = s3;
    node3->left = node2;
    node3->right = NULL;
    node2->right = node3;
    
    Node* node4 = new Node;
    node4->value = s4;
    node4->left = node3;
    node4->right = NULL;
    node3->right = node4;
    
    node1->left = node4;
    node1->right = node2;
    node2->right = node3;
    node3->right = node4;

    return node1;
}
bool compareStringsAlphabetically(const std::string& str1, const std::string& str2)
{
    int len = std::min(str1.length(), str2.length());
    for (int i = 0; i < len; i++) {
        if (str1[i] < str2[i]) {
            return true;
        } else if (str1[i] > str2[i]) {
            return false;
        }
    }
    // if the common prefix is equal, compare based on the length of the strings
    return (str1.length() < str2.length());
}

void sortPlaylist(Node *node) {
    Node* aux = NULL, * aux2 = NULL, * aux3 = NULL, * aux4 = NULL;
	string valor = "", valor2 = ""; 
    int i = 0, j = 0, k = 0, inicio = 0, total = 0;
	aux = node;
	while (aux != NULL)
	{
		//cout << aux->value << " ";
		aux = aux->right;
	}
	cout << "\n";
	aux = node;
	while (aux != NULL)  //total de nodos
	{
		total++;
		aux = aux->right;
	}
	aux = node;
	aux3 = node;
	aux2 = node->right;
	valor = aux->value.name;
	while (aux->right != NULL)
	{
		for (i = inicio; i <= total-2; i++)
		{
            
			if(compareStringsAlphabetically(aux2->value.name, aux3->value.name)) 
			{
				valor2 = aux2->value.name;
				aux3 = aux2;
				aux2 = aux2->right;
			}
			else
			{
				aux2 = aux2->right;
			}
		}
		cout << "Valor minimo: " << valor << "\n";
		cout << "valor maximo: " << valor2 << "\n";
		aux->value.name = valor2;
		aux3->value.name = valor;
		aux = aux->right;
		aux2 = aux->right;
		aux3 = aux;
		inicio++;
		valor = aux->value.name;
		if (aux->right != NULL)
		{
			valor2 = aux2->value.name;
		}
		aux4 = node;
		while (aux4 != NULL)
		{
			//cout << aux4->value << " ";
			aux4 = aux4->right;
		}
		cout << "\n";
	}
}