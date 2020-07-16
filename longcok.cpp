#include <bits/stdc++.h>
using namespace std;
using ll long long int;
int main()
{

    int t;
    cin>>t;
    while(t--) {
        ll m1,y1,m2,y2;
        cin>>m1>>y1>>m2>>y2;
        if(m1>2)
        {   m1=2;
            y1++;

        } else
        {
            m1=2;
        }
        if(m2<2)
        {
            m2=2;
            y2--;

        } else
        {
            m2=2;
        }

ll cnt=0;
ll c1=y1/100,c2=y2/100;
        if(c2-c1<=1)
        {
            for(ll i=y1;i<=y2;i++)
            {


                ll p=(32-(2*(i/100))+((i%100)-1)+((i%100)-1)/4 + ((i/100)/4) )%7;
                ll q=(33-(2*(i/100))+((i%100)-1)+((i%100)-1)/4 + ((i/100)/4) )%7;
//            if(i==2015)
//            {
//                cout<<p<<" "<<q<<"\n";
//            }
                if(q==0)
                {  // cout<<i<<"\n";
                    cnt++;
                    continue;

                }
                else if(p==0)
                {
                    if(!(i%400==0||(i%4==0&&i%100!=0)))
                    {
                        // cout<<i<<"\n";
                        cnt++;
                    }


                }
            }
            cout<<cnt<<"\n";

        } else
        {

            ll x=c1*100+99;
            ll a=0;
            for(ll i=y1;i<=x;i++)
            {

                ll p=(32-(2*(i/100))+((i%100)-1)+((i%100)-1)/4 + ((i/100)/4) )%7;
                ll q=(33-(2*(i/100))+((i%100)-1)+((i%100)-1)/4 + ((i/100)/4) )%7;

                if(q==0)
                {  // cout<<i<<"\n";
                    a++;
                    continue;

                }
                else if(p==0)
                {
                    if(!(i%400==0||(i%4==0&&i%100!=0)))
                    {
                        // cout<<i<<"\n";
                        a++;
                    }
                }
            }
            ll y=c2*100;
            ll b=0;
            for(ll i=y;i<=y2;i++)
            {

                ll p=(32-(2*(i/100))+((i%100)-1)+((i%100)-1)/4 + ((i/100)/4) )%7;
                ll q=(33-(2*(i/100))+((i%100)-1)+((i%100)-1)/4 + ((i/100)/4) )%7;
//            if(i==2015)
//            {
//                cout<<p<<" "<<q<<"\n";
//            }
                if(q==0)
                {  // cout<<i<<"\n";
                    b++;
                    continue;

                }
                else if(p==0)
                {
                    if(!(i%400==0||(i%4==0&&i%100!=0)))
                    {
                        // cout<<i<<"\n";
                        b++;
                    }


                }
            }
            ll z=c1+1;
            ll zz=c2-1;
            ll aaa=z%4;
            ll tot=zz-z+1;
            ll jod=tot/4;
            ll c=0;
            c+=(25*jod);
            c+=(24*jod);
            c+=(26*jod);
            c+=(26*jod);
            map<ll,ll> mp;
            mp[0]=25;
            mp[1]=24;
            mp[2]=26;
            mp[3]=26;
            for(ll i=aaa;i<aaa+(tot%4);i++)
            {
                c+=mp[i%4];
            }
cout<<a+b+c<<"\n";





        }





    }




}
