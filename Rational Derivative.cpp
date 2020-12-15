/* Link to the problem: https://putka-upm.acm.si/tasks/t/odvod-racionalne-funkcije/ */
#include <iostream>

#include <algorithm>

#include <map>

#include <vector>

using namespace std;

class Poly{

    public:

 

    vector<long long> arr;

    Poly(vector<long long> arr_){

        arr=arr_;

    }

    long long degree()const{

        return arr.size()-1;

    }

    static long long gcd(long long a,long long b){

        if (b==0){

            return a;

        }

        return gcd(b,a%b);

    }

    Poly mul(const Poly& rhs){

        long long d=degree()+rhs.degree();

 

        Poly res=Poly::createNew(d);

        for (long long i=0;i<arr.size();++i){

            for (long long j=0;j<rhs.arr.size();++j){

                res.arr[i+j]+=arr[i]*rhs.arr[j];

            }

        }

        res.adjustDegree();

        return res;

    }

    Poly add(const Poly& rhs,long long sign=1){

        long long mx=max(arr.size(),rhs.arr.size());

        Poly res=Poly::createNew(mx-1);

        for (long long i=0;i<mx;++i){

            res.arr[i]=0;

            if (i<arr.size()){

                res.arr[i]+=arr[i];

            }

            if (i<rhs.arr.size()){

                res.arr[i]+=rhs.arr[i]*sign;

            }

        }

        res.adjustDegree();

        return res;

    }

    Poly clone() const{

        return Poly(arr);

    }

    void mul(long long v){

        for(auto& it:arr){

            it*=v;

        }

    }

    void div(long long v){

        for(auto& it:arr){

            it/=v;

        }

    }

    long long find_gcd(){

        long long v=arr[0];

        for (auto& it:arr){

            v=Poly::gcd(v,it);

        }

        return v;

    }

 

    Poly differentiate(){

        if (degree()==0){

            return Poly::createNew(0);

        }

        Poly res=Poly::createNew(degree()-1);

        for (long long i=1;i<arr.size();++i){

            res.arr[i-1]=i*arr[i];

        }

        res.adjustDegree();

        return res;

    }

    void addTerm(long long d,long long v){

        if (d>=arr.size()){

            arr.resize(d+1);

        }

        arr[d]+=v;

    }

 

    pair<Poly,pair<Poly,Poly>> divide(const Poly& rhs){

        long long d=degree()-rhs.degree();

        Poly rem=clone();

        Poly q=rhs.clone();

        Poly res=Poly::createNew(0);

        if (d>=0){

            res=Poly::createNew(d);

            while (rem.degree()>=q.degree() && !rem.is_zero()){

                long long d=rem.degree()-rhs.degree();

                long long v=rem.arr.back()/q.arr.back();

                res.addTerm(d,v);

                rem=this->add(res.mul(q),-1);

            }

        }

        long long p=rem.find_gcd();

        long long p2=q.find_gcd();

        long long v=Poly::gcd(p,p2);

        if (v!=1){

            rem.div(v);

            q.div(v);

        }

        if (q.arr.back()<0){

            rem.div(-1);

            q.div(-1);

        }

        return {res,{rem,q}};

    }

    void adjustDegree(){

        while(arr.size()>1 && arr.back()==0){

            arr.pop_back();

        }

    }

    static Poly createNew(long long degree){

        return Poly(vector<long long>(degree+1));

    }

    static Poly read(long long degree){

        Poly p=Poly::createNew(degree);

        for (long long i=p.arr.size()-1;i>=0;--i){

            cin>>p.arr[i];

        }

        p.adjustDegree();

        return p;

    }

    void write(){

        for (long long i=arr.size()-1;i>=0;--i){

            cout<<arr[i]<<" \n"[i==0];

        }

    }

    bool is_zero(){

        return degree()==0 && arr[0]==0;

    }

};

 

int main(){

    //freopen("file.in","r",stdin);

    int n;

    cin>>n;

    auto p=Poly::read(n);

    cin>>n;

    auto q=Poly::read(n);

    if (q.degree()==0){

        p.div(q.arr[0]);

        auto pPrime=p.differentiate();

        pPrime.write();

    }else{

        auto pPrime=p.differentiate();

        auto qPrime=q.differentiate();

        auto nom=pPrime.mul(q).add(p.mul(qPrime),-1);

        auto denom=q.mul(q);

        auto ans=nom.divide(denom);

        ans.first.write();

        if (!ans.second.first.is_zero()){

            ans.second.first.write();

            ans.second.second.write();

        }

    }

 

}
