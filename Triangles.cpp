#include <iostream>

#include <algorithm>

#include <cmath>

using namespace std;

const long long mx=50009;

struct Point{

    int x;

    int y;

};

Point points[mx];

pair<long double,string> triangles[mx];

 

long long length(Point a,Point b){

    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));

}

long long eps=1e-6;

bool closeEnough(long long v1,long long v2){

    return abs(v1-v2)<eps;

}

long long calcSize(long long a,long long b,long long c){

    long long s=(a+b+c)/2;

    return sqrt(s*(s-a)*(s-b)*(s-c));

}

 

long long calcSize(Point A,Point B,Point C){

    return abs(A.x*(B.y-C.y) + B.x*(C.y-A.y) + C.x*(A.y-B.y));

}

 

 

int main(){

    //freopen("file.in","r",stdin);

    int n,m;

    ios::sync_with_stdio(false);

    cin>>n>>m;

    for (int i=0;i<n;++i){

        cin>>points[i].x>>points[i].y;

    }

    for (int i=0;i<m;++i){

        cin>>triangles[i].second;

        Point A,B,C;

        cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;

        auto tri=calcSize(A,B,C);

        int score=0;

        for (int j=0;j<n;++j){

            auto tri1=calcSize(points[j],A,B);

            auto tri2=calcSize(points[j],B,C);

            auto tri3=calcSize(points[j],A,C);

            if (tri==tri1+tri2+tri3){

                score+=1;

            }

        }

        triangles[i].first=-1.0*score/tri;

    }

    sort(triangles,triangles+m);

    for(int i=0;i<m;++i){

        cout<<triangles[i].second<<endl;

        //cout<<triangles[i].first<<endl;

    }

}



/*Link to the problem https://putka-upm.acm.si/tasks/t/najbermudskejsi-trikotnik/*/


