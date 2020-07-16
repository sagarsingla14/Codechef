tc {
  ll n,l;
  cin>>n>>l;

  if((n&1))
  {
      cout<<0<<"\n";
      continue;
  }


  int x=n/2,y=l/2;
  ll dsp[x+1]={0};
  dsp[0]=1;

  forb(i,1,x+1)
  {
      forb(j,1,min(y,i)+1)
      {
          dsp[i]+=dsp[i-j];
          dsp[i]%=mod;
      }
  }
ll ans=dsp[x];
  cout<<ans<<"\n";
//    cout<<dsp[x]<<n";
}

return 0;
