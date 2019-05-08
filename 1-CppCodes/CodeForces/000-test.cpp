ll mypow(ll a, ll b){
    if(b==0){   return 1;   }
    if(b==1){   return a;   }
    ll ret = 0;
    int b1 = b>>1;
    ret = pow(a,b1);
    while(ret>=MODULO){ ret-=MODULO;    }
    ret = ret*ret;
    while(ret>=MODULO){ ret-=MODULO;    }
    
    if( (b&1) == 1){
        ret = ret*a;
        while(ret>=MODULO){ ret-=MODULO;    }
    }

    return ret;
}