#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


class Car{
public:
    string id;
    int x,y;

    Car(string id, int x, int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int dist() const {
        return x*x + y*y;
    }
};


class CarCompare{

    private:
        /* data */
    public:
        bool operator()(const Car A, const Car B){
            return A.dist() < B.dist(); //Max Heap
            //return A.dist() > B.dist(); //Min Heap
        }

};


void printNearestCars(vector<Car> cars, int k){

    priority_queue<Car, vector<Car>, CarCompare> maxHeap(cars.begin(),cars.begin()+k);

    for(int i = k; i<cars.size();i++){
        auto car = cars[i];

        if(car.dist() < maxHeap.top().dist()){
            maxHeap.pop();
            maxHeap.push(car);
        }
    }

    vector<Car> output;

    while(!maxHeap.empty()){
        //cout<<maxHeap.top().id<<endl;
        output.push_back(maxHeap.top());
        maxHeap.pop();
    }

    reverse(output.begin(), output.end());

    for(auto car : output){
        cout<<car.id<<" ";
    }

    return;
}

int main(int argc, char const *argv[])
{
    int N,K;
    cin>>N>>K;

    string id;
    int x,y;
    vector<Car> cars;

    for(int i =0; i<N;i++){
        cin>>id>>x>>y;
        Car car(id,x,y);
        cars.push_back(car);
    }

    printNearestCars(cars,K);
    return 0;
}
