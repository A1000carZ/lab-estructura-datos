#include <iostream>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <vector>

using namespace std;

struct song
{
    string name;
    string author;
    int duration;
    song() : name("Prueba"), author("prueba"), duration(0) {}
    song(string name, string author, int duration) : name(name), author(author), duration(duration) {}
};

struct Node
{
    song value;
    Node *right;
    Node *left;
};

struct playlist
{
    string name;
    Node *songs;
    playlist() : name(""), songs(NULL) {}
    playlist(string name, Node *node) : name(name), songs(songs) {}
};

playlist createPlaylist();
void printAllPlaylists(vector<playlist> playlists);
void printPlaylist(Node *node);
Node *playPreviousSong(Node *node);
Node *playNextSong(Node *node);
Node *deleteSong(Node *node, song song);
Node *defaultList();
Node *addSongAtBeginning(Node *Node);
Node *addSongAtEnd(Node *Node);
Node *queuePlayList(Node *node);
Node *favtoritesList(Node *node);
void sortPlaylistByName(Node *node);
void sortPlaylistByAuthor(Node *node);

int main()
{
    vector<playlist> playlists;
    Node *head = NULL;
    Node *favorites = NULL;
    head = defaultList(); // create a default playlist
    playlist mainPlaylist = playlist("Mi playlist", head);
    playlist favoritesPlaylist = playlist("Favorite playlist", favorites);
    playlists.push_back(mainPlaylist);
    playlists.push_back(favoritesPlaylist);
    playlist newPlaylist;
    char choice;
    while (true)
    {
        printAllPlaylists(playlists);
        cout << endl;
        cout << "\t[n] Crear playlist [r] Reproducir playlist"<<endl;
        cout << "\tSelecciona una opcion: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 'n':
            system("clear");
            newPlaylist = createPlaylist();
            playlists.push_back(newPlaylist);
            system("clear");
            break;
        case 'r':
            break;
        default:
            cout << "Lo siento no pudimos procesar su respuesta";
            system("clear");
            break;
        }
    }

    return 0;
}

playlist createPlaylist()
{
    Node *songs = new (Node);
    playlist newPlaylist;
    newPlaylist.name = "nuevo"; // set the name of the playlist to "nuevo"
    newPlaylist.songs = songs;

    cout << "Ingresa el nombre de la playlist: ";
    cin >> newPlaylist.name;
    song s;
    cout << "Agrega al menos una cancion" << endl;
    cout << "Ingresa el nombre de la cancion: ";
    cin >> s.name;
    fflush(stdin);
    cout << "Ingresa el autor de la cancion: ";
    cin >> s.author;
    fflush(stdin);
    cout << "Ingresa la duracion de la cancion (en segundos): ";
    cin >> s.duration;
    fflush(stdin);
    cout << endl;
    songs->value = s;
    songs->right = NULL;
    songs->left = NULL;

    return newPlaylist;
}

void printAllPlaylists(vector<playlist> playlists)
{
    string header =
        "\n"
        "******************************************************************\n"
        "*                                                                *\n"
        "*                      Playlists Disponibles                     *\n"
        "*                                                                *\n"
        "******************************************************************\n";

    // Define styles for the playlist names
    string playlistStyle =
        "\033[1m\033[32m"  // bold and green text
        "{number}. {name}" // playlist item template
        "\033[0m\n";       // reset style
    cout << "\033[1m\033[32m";
    std::cout << "                                                                                   " << std::endl;
    std::cout << " ad88888ba                                     88     ad88                     " << std::endl;
    std::cout << "d8\"     \"8b                             ,d     \"\"    d8\"                       " << std::endl;
    std::cout << "Y8,                                     88           88                        " << std::endl;
    std::cout << "`Y8aaaaa,    8b,dPPYba,    ,adPPYba,  MM88MMM  88  MM88MMM  8b       d8          " << std::endl;
    std::cout << "  `\"\"\"\"\"8b,  88P'    \"8a  a8\"     \"8a   88     88    88     `8b     d8'         " << std::endl;
    std::cout << "        `8b  88       d8  8b       d8   88     88    88      `8b   d8'           " << std::endl;
    std::cout << "Y8a     a8P  88b,   ,a8\"  \"8a,   ,a8\"   88,    88    88       `8b,d8'            " << std::endl;
    std::cout << " \"Y88888P\"   88`YbbdP\"'    `\"YbbdP\"'    \"Y888  88    88         Y88'             " << std::endl;
    std::cout << "             88                                                 d8'              " << std::endl;
    std::cout << "             88                                                d8'               " << std::endl;
    cout << "\033[0m\n";
    cout << header;

    for (int i = 0; i < playlists.size(); i++)
    {
        cout << (char)176 << "  " << i + 1 << ". " << playlists[i].name << endl;
    }
    cout << "******************************************************************" << endl;
}

Node *addSongAtBeginning(Node *lastNode)
{
    int value;
    song s;
    cout << "Ingresa el nombre de la cancion: ";
    cin >> s.name;
    cout << "Ingresa el autor de la cancion: ";
    cin >> s.author;
    cout << "Ingresa la duracion de la cancion (en segundos): ";
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
    cout << "Ingresa el nombre de la cancion: ";
    cin >> s.name;
    cout << "Ingresa el autor de la cancion: ";
    cin >> s.author;
    cout << "Ingresa la duracion de la cancion (en segundos): ";
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
         << "\tEstatus de Playlist" << endl
         << endl;
    while (temp != NULL)
    {
        cout << "\t" << temp->value.name << " - " << temp->value.author << endl;
        // if (temp->right != NULL)
        //     cout << " 👉 ";
        temp = temp->right;
    }
    cout << endl;
}

Node *playPreviousSong(Node *node)
{
    // implement code to play the previous song
    if (node->left == NULL)
    {
        cout << "No previous song available." << endl;
        return node;
    }
    else
    {
        return node->left;
    }
}

Node *playNextSong(Node *node)
{
    // implement code to play the next song
    if (node->right == NULL)
    {
        cout << "End of playlist reached." << endl;
        return node;
    }
    else
    {
        return node->right;
    }
}

Node *deleteSong(Node *node, song s)
{
    if (node == NULL)
    {
        return node;
    }
    if (node->value.name == s.name && node->value.author == s.author && node->value.duration == s.duration)
    {
        // The song to be deleted is the head node
        Node *temp = node->right;
        if (temp != NULL)
        {
            temp->left = NULL;
        }
        delete node;
        return temp;
    }
    node->right = deleteSong(node->right, s);
    return node;
}

Node *defaultList()
{
    song s1("Elephant In The Room", "Confetti", 180);
    song s2("Stand By Me", "John Lennon", 210);
    song s3("Are You Ready", "AC/DC", 240);
    song s4("Cactus", "Gustavo Cerati", 270);

    Node *node1 = new Node;
    node1->value = s1;
    node1->left = NULL;
    node1->right = NULL;

    Node *node2 = new Node;
    node2->value = s2;
    node2->left = node1;
    node2->right = NULL;
    node1->right = node2;

    Node *node3 = new Node;
    node3->value = s3;
    node3->left = node2;
    node3->right = NULL;
    node2->right = node3;

    Node *node4 = new Node;
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
bool compareStringsAlphabetically(const std::string &str1, const std::string &str2)
{
    int len = std::min(str1.length(), str2.length());
    for (int i = 0; i < len; i++)
    {
        if (str1[i] < str2[i])
        {
            return true;
        }
        else if (str1[i] > str2[i])
        {
            return false;
        }
    }
    // if the common prefix is equal, compare based on the length of the strings
    return (str1.length() < str2.length());
}

void sortPlaylistByName(Node *node)
{
    Node *aux = NULL, *aux2 = NULL, *aux3 = NULL, *aux4 = NULL;
    song valor, valor2;
    int i = 0, j = 0, k = 0, inicio = 0, total = 0;
    aux = node;
    while (aux != NULL)
    {
        // cout << aux->value << " ";
        aux = aux->right;
    }
    cout << "\n";
    aux = node;
    while (aux != NULL) // total de nodos
    {
        total++;
        aux = aux->right;
    }
    aux = node;
    aux3 = node;
    aux2 = node->right;
    valor = aux->value;
    while (aux->right != NULL)
    {
        for (i = inicio; i <= total - 2; i++)
        {
            if (compareStringsAlphabetically(aux2->value.name, aux3->value.name))
            {
                valor2 = aux2->value;
                aux3 = aux2;
                aux2 = aux2->right;
            }
            else
            {
                aux2 = aux2->right;
            }
        }
        cout << "Valor minimo: " << valor.name << "\n";
        cout << "valor maximo: " << valor2.name << "\n";
        aux->value = valor2;
        aux3->value = valor;
        aux = aux->right;
        aux2 = aux->right;
        aux3 = aux;
        inicio++;
        valor = aux->value;
        if (aux->right != NULL)
        {
            valor2 = aux2->value;
        }
        aux4 = node;
        while (aux4 != NULL)
        {
            // cout << aux4->value << " ";
            aux4 = aux4->right;
        }
        cout << "\n";
    }
}

void sortPlaylistByAuthor(Node *node)
{
    Node *aux = NULL, *aux2 = NULL, *aux3 = NULL, *aux4 = NULL;
    song valor, valor2;
    int i = 0, j = 0, k = 0, inicio = 0, total = 0;
    aux = node;
    while (aux != NULL)
    {
        // cout << aux->value << " ";
        aux = aux->right;
    }
    cout << "\n";
    aux = node;
    while (aux != NULL) // total de nodos
    {
        total++;
        aux = aux->right;
    }
    aux = node;
    aux3 = node;
    aux2 = node->right;
    valor = aux->value;
    while (aux->right != NULL)
    {
        for (i = inicio; i <= total - 2; i++)
        {
            if (compareStringsAlphabetically(aux2->value.author, aux3->value.author))
            {
                valor2 = aux2->value;
                aux3 = aux2;
                aux2 = aux2->right;
            }
            else
            {
                aux2 = aux2->right;
            }
        }
        cout << "Valor minimo: " << valor.name << "\n";
        cout << "valor maximo: " << valor2.name << "\n";
        aux->value = valor2;
        aux3->value = valor;
        aux = aux->right;
        aux2 = aux->right;
        aux3 = aux;
        inicio++;
        valor = aux->value;
        if (aux->right != NULL)
        {
            valor2 = aux2->value;
        }
        aux4 = node;
        while (aux4 != NULL)
        {
            // cout << aux4->value << " ";
            aux4 = aux4->right;
        }
        cout << "\n";
    }
}
