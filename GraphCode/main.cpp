//
//  main.cpp
//  GraphCode
//
//  Created by Edik Shklyar on 7/28/16.
//  Copyright © 2016 SwiftTech. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>


using namespace std;

class Record{
public:
    int head;
    int tail;
    void set_values (int,int);
};

void Record::set_values (int x, int y) {
    head = x;
    tail = y;
}

class DataSource: public Record {
protected:
    string line;
    //    ifstream inputFile;
    //    stringstream *ss;
public:
    int numberOfVerts;
    vector <Record> listOfRecords;
    vector<Record>::iterator listOfRecordsIterator;
    void addRecords (Record &);
    void readFromFile (string *);
    void nOfVer (vector <Record> *);
};
void DataSource::nOfVer (vector<Record> *vec){

    Record temp = vec->back();
    int a = temp.head;
    int b = temp.tail;

    numberOfVerts = max(a, b);
};
void DataSource::addRecords(Record &r){
    listOfRecords.push_back(r);
    cout << "from add Records func" << listOfRecords.size() << "\n";

};

void DataSource::readFromFile(string *myFile){
    //    cout <<"myFile is " << myFile << "\n";
    int a,b;
    //    Record *temp = new Record();
    Record tmp;
    ifstream ifs (*myFile);
    cout <<"ifs is " << &ifs << "\n";
    if (ifs.is_open())
    {
        cout << "file is open \n";
        while (getline(ifs, line))
        {
            stringstream ss(line);
            ss >> a >> b;
            //            temp -> set_values(a, b);
            //            (*temp).set_values(a, b);
            tmp.set_values(a, b);
            //            addRecords(temp);
            Record *tmpR = &tmp;
            addRecords(*tmpR);
            //            addRecords(&tmp);
            //              cout <<" back listOfEdges" << listOfRecords.size() <<" \n";
        }
    }

    else{
        cout << "Unable to open file";
    }
    //    delete temp;
    //    cout << "list of records" << &listOfRecords.back() << "\n";
    for(listOfRecordsIterator = listOfRecords.begin();
        listOfRecordsIterator != listOfRecords.end();
        listOfRecordsIterator++)
    {
        cout << (*listOfRecordsIterator).head<<" head listOfRecordsIterator \n";
    }
    //assign the number of verticies
    //    vector<Record> *temp = &listOfRecords;
    nOfVer(&listOfRecords);
    //    nOfVer (temp);

}

//int numberOfVertices (vector<Record> *vec){
//    Record temp = vec->back();
//
//
//    int a = temp.head;
//    int b = temp.tail;
//
//    int number = max(a, b);
//
//    return number;
//}


class Vertex{
public:
    int number;
    int NumberOfVer;
    //    void getNumberOfVer(vector<Record> *vec);

    //    typedef unsigned int Number;
    //protected: Number number;
    //public:
    Vertex (int);
    //    virtual operator Number () const;

};
Vertex::Vertex(int x){
    number = x;
};

//void Vertex::getNumberOfVer(vector<Record> *vec){
//
//    int numberOfVertices (vector<Record> vec){
//        Record temp = vec.back();
//        int a = temp.head;
//        int b = temp.tail;
//
//        int number = max(a, b);
//
//        return number;
//
//};

class Edge{
protected:
    int head;
    int tail;
public:
    Vertex *destination;
    Edge(int, int);
};

Edge::Edge(int x, int y){
    head = x;
    tail = y;
}


class Graph{
protected:
    int numberOfVerticies;
    int numberOfEdges;


public:
    void setNumberOfVert(int);
    int verticies();
    int edges();
    void addEdge(Edge &);
    bool isConnected();
    bool isEdge(int, int);
    void BreathFirstTraversal();
    void AddVertex(int);
    Graph() = default;
    ~Graph() = default;
    list <Vertex> vertices;
};
void Graph::AddVertex(int number){
    for( auto &v : vertices )
        if( v.number == number )
            return;
    vertices.push_back( Vertex(number) );
}

void Graph::setNumberOfVert(int x){
    numberOfVerticies = x;

}
int Graph::verticies(){
    return numberOfVerticies;
}

int Graph::edges(){
    return numberOfEdges;
}


//int Graph::edges(){
//
//    return numberOfVerticies;
//};

class GraphAsAdjList{

public:
    int numberOfVertiecies;
    void makeList();
    vector<list<int>> adjList() ;
    vector<list<int>>::iterator adjListIterator;
    void getNumOfVer(int *);
    void populateListWithRecords(int , int );
};
void GraphAsAdjList::getNumOfVer(int *x ){
    numberOfVertiecies = *x;
    //     vector<list<int>> adjList(numberOfVertiecies) ;
    //    adjList[0].push_back(<#value_type &&__x#>)
}
//makes a default list --- constructor?
//void GraphAsAdjList::makeList(){
//    vector<list<int>> adjList(numberOfVertiecies);
//    for (int i=1; i <= numberOfVertiecies; i++ ){
//
//
//    }
//
//}


void GraphAsAdjList::populateListWithRecords(int x, int y){

    //    adjList[x].push_back(y);


    //    adjList[x].push_back(y);

}
//void GraphAsAdjList::makeList(int x){
//
//    vector<list<int>> adjList( int x);
//    adjList[Vertex(int x)] =
//
//
//
//
//
//
//    int n;
//    list <int> adj;
//    AdjacencyLists(int n0) {
//        n = n0;
//        adj = (List<Integer>[])new List[n];
//        for (int i = 0; i < n; i++)
//            adj[i] = new ArrayStack<Integer>(Integer.class);
//
//}




int main(int argc, const char * argv[]) {

    string fileName = "sample.txt";

    DataSource dd;
    dd.readFromFile(&fileName);

    //    vector<Record> *temp = &dd.listOfRecords;
    //
    //     dd.nOfVer (temp);


    ////macke a call from graph

    //    int numberOFVerticiesInGraph = numberOfVertices(temp);


    //    int numberOFVerticiesInGraph = numberOfVertices(&dd.listOfRecords);
    //same thing
    int * nOfVertInGraph = &dd.numberOfVerts;


    //    cout << "numberOFVerticiesInGraph 1" << numberOFVerticiesInGraph << " ";
    cout << "numberOFVerticiesInGraph 2" << dd.numberOfVerts << " ";

    GraphAsAdjList GAL;

    GAL.getNumOfVer(nOfVertInGraph);
    cout<< "lalalala" << GAL.numberOfVertiecies <<"lala\n";
    int x =GAL.numberOfVertiecies;

    vector<list<int>>myAdjList (GAL.numberOfVertiecies);
    vector<list<int>>::iterator myAdjListIt;

    for(dd.listOfRecordsIterator = dd.listOfRecords.begin();
        dd.listOfRecordsIterator != dd.listOfRecords.end();
        dd.listOfRecordsIterator++)
    {

        myAdjList[(*dd.listOfRecordsIterator).head].push_back((*dd.listOfRecordsIterator).tail);

        myAdjList[(*dd.listOfRecordsIterator).tail].push_back((*dd.listOfRecordsIterator).head);
    }
    int c=1;
    for (myAdjListIt=myAdjList.begin(); myAdjListIt!= myAdjList.end(); ++myAdjListIt)
    {
        cout <<"my c is "<< c <<"\n";

        list<int> li = *myAdjListIt;
        for (list<int>::iterator i= li.begin(); i!=li.end(); ++i) {
            cout << *i << "my i \n";
        }
        cout <<"end of i loop" << c << "  \n";
        c++;
    }

    //
    //        cout << (*dd.listOfRecordsIterator).head<<" head listOfRecordsIterator \n";


    cout << myAdjList[1].back() << "some some \n";

    for(int i=1; i<10; i++)
    {
        cout << myAdjList[i].back() << "some some \n";
    }
    
    //    DataSource *d = new DataSource();
    //    d->readFromFile(&fileName);
    
    cout << "Hello, World!\n";
    
    Vertex *v0;
    v0 = 0;
    
    return 0;
}

