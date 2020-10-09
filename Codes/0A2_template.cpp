#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long 

class Soln{
private:
    int n;
public:
    Soln(){}
    ~Soln(){}
};

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	return 0;
}


/*                                           When Panda is Life !
 
                              _,add8ba,
                            ,d888888888b,
                           d8888888888888b                        _,ad8ba,_
                          d888888888888888)                     ,d888888888b,
                          I8888888888888888 _________          ,8888888888888b
                __________`Y88888888888888P"""""""""""baaa,__ ,888888888888888,
            ,adP"""""""""""9888888888P""^                 ^""Y8888888888888888I
         ,a8"^           ,d888P"888P^                           ^"Y8888888888P'
       ,a8^            ,d8888'                                     ^Y8888888P'
      a88'           ,d8888P'                                        I88P"^
    ,d88'           d88888P'                                          "b,
   ,d88'           d888888'                                            `b,
  ,d88'           d888888I                                              `b,
  d88I           ,8888888'            ___                                `b,
 ,888'           d8888888          ,d88888b,              ____            `b,
 d888           ,8888888I         d88888888b,           ,d8888b,           `b
,8888           I8888888I        d8888888888I          ,88888888b           8,
I8888           88888888b       d88888888888'          8888888888b          8I
d8886           888888888       Y888888888P'           Y8888888888,        ,8b
88888b          I88888888b      `Y8888888^             `Y888888888I        d88,
Y88888b         `888888888b,      `""""^                `Y8888888P'       d888I
`888888b         88888888888b,                           `Y8888P^        d88888
 Y888888b       ,8888888888888ba,_          _______        `""^        ,d888888
 I8888888b,    ,888888888888888888ba,_     d88888888b               ,ad8888888I
 `888888888b,  I8888888888888888888888b,    ^"Y888P"^      ____.,ad88888888888I
  88888888888b,`888888888888888888888888b,     ""      ad888888888888888888888'
  8888888888888698888888888888888888888888b_,ad88ba,_,d88888888888888888888888
  88888888888888888888888888888888888888888b,`"""^ d8888888888888888888888888I
  8888888888888888888888888888888888888888888baaad888888888888888888888888888'
  Y8888888888888888888888888888888888888888888888888888888888888888888888888P
  I888888888888888888888888888888888888888888888P^  ^Y8888888888888888888888'
  `Y88888888888888888P88888888888888888888888888'     ^88888888888888888888I
   `Y8888888888888888 `8888888888888888888888888       8888888888888888888P'
    `Y888888888888888  `888888888888888888888888,     ,888888888888888888P'
     `Y88888888888888b  `88888888888888888888888I     I888888888888888888'
       "Y8888888888888b  `8888888888888888888888I     I88888888888888888'
         "Y88888888888P   `888888888888888888888b     d8888888888888888'
            ^""""""""^     `Y88888888888888888888,    888888888888888P'
                             "8888888888888888888b,   Y888888888888P^
                              `Y888888888888888888b   `Y8888888P"^
                                "Y8888888888888888P     `""""^
                                  `"YY88888888888P'
                                       ^""""""""'
  */

//                                        .....'',;;::cccllllllllllllcccc:::;;,,,''...'',,'..
//                             ..';cldkO00KXNNNNXXXinp000OOinpinpkxxxxxddoooddddddxxxxinpinpOO0XXKx:.
//                       .':ok0KXXXNXK0kxolc:;;,,,,,,,,,,,;;,,,''''''',,''..              .'lOXKd'
//                  .,lx00Oxl:,'............''''''...................    ...,;;'.             .oKXd.
//               .cinpinpc'...'',:::;,'.........'',;;::::;,'..........'',;;;,'.. .';;'.           'kNKc.
//            .:kXXk:.    ..       ..................          .............,:c:'...;:'.         .dNNx.
//           :0NKd,          .....''',,,,''..               ',...........',,,'',,::,...,,.        .dNNx.
//          .xXd.         .:;'..         ..,'             .;,.               ...,,'';;'. ...       .oNNo
//          .0K.         .;.              ;'              ';                      .'...'.           .oXX:
//         .oNO.         .                 ,.              .     ..',::ccc:;,..     ..                lXX:
//        .dNX:               ......       ;.                'cxOinp0OXWWWWWWWNX0kc.                    :KXd.
//      .l0N0;             ;d0inpinpKXK0ko:...              .l0X0xc,...lXWWWWWWWWKO0Kx'                   ,ONKo.
//    .lKNKl...'......'. .dXWN0inpk0NWWWWWN0o.            :KN0;.  .,cokXWWNNNNWNinpxONK: .,:c:.      .';;;;:lk0XXx;
//   :KN0l';ll:'.         .,:lodxxkO00KXNWWWX000k.       oXNx;:oinpX0kdl:::;'',;coxinpd, ...'. ...'''.......',:lxKO:.
//  oNNk,;c,'',.                      ...;xNNOc,.         ,d0X0xc,.     .dOd,           ..;dOKXK00000Ox:.   ..''dKO,
// 'KW0,:,.,:..,oxinpkdl;'.                'inp'              ..           .dXX0o:'....,:oOXNN0d;.'. ..,lOKd.   .. ;KXl.
// ;XNd,;  ;. l00kxoooxKXKx:..ld:         ;inp'                             .:dkO000000Okxl;.   c0;      :inp;   .  ;XXc
// 'XXdc.  :. ..    '' 'kNNNinpinp,      .,dKNO.                                   ....       .'c0NO'      :X0.  ,.  xN0.
// .kNOc'  ,.      .00. ..''...      .l0X0d;.             'dOkxo;...                    .;oinpXK0KNXx;.   .0X:  ,.  lNX'
//  ,inpdl  .c,    .dNK,            .;xXWKc.                .;:coOXO,,'.......       .,lx0XXOo;...oNWNXinp:.'KX;  '   dNX.
//   :XXkc'....  .dNWXl        .';l0NXNKl.          ,lxinpkxo' .cK0.          ..;lx0XNX0xc.     ,0Nx'.','.kXo  .,  ,KNx.
//    cXXd,,;:, .oXWNNKo'    .'..  .'.'dinp;        .cooollox;.xXXl     ..,cdOKXXX00NXc.      'oKWK'     ;k:  .l. ,0Nk.
//     cXNx.  . ,KWX0NNNXOl'.           .o0Ooldk;            .:c;.':lxOinpK0xo:,.. ;XX:   .,lOXWWXd.      . .':,.lKXd.
//      lXNo    cXWWWXooNWNXinpo;'..       .lk0x;       ...,:ldk0KXNNOo:,..       ,OWNOxO0KXXNWNO,        ....'l0Xk,
//      .dNK.   oNWWNo.cXK;;oOXNNXK0kxdolllllooooddxk00inpinp0kdoc:c0No        .'ckXWWWNXkc,;kNKl.          .,kXXk,
//       'KXc  .dNWWX;.xNk.  .kNO::lodxkOXWN0OkxdlcxNKl,..        oN0'..,:ox0XNWWNNWXo.  ,ONO'           .o0Xk;
//       .ONo    oNWWN0xXWK, .oNKc       .ONx.      ;X0.          .:XNinpNNWWWWNinpl;kNk. .cKXo.           .ON0;
//       .xNd   cNWWWWWWWWKOinpNXxl:,'...;0Xo'.....'lXK;...',:lxk0KNWWWWNNKOd:..   lXKclON0:            .xNk.
//       .dXd   ;XWWWWWWWWWWWWWWWWWWNNNNNWWNNNNNNNNNWWNNNNNNWWWWWNXKNNk;..        .dNWWXd.             cXO.
//       .xXo   .ONWNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNNK0ko:'..OXo          'l0NXx,              :inp,
//       .OXc    :XNk0NWXKNWWWWWWWWWWWWWWWWWWWWWNNNX00NNx:'..       lXKc.     'lONN0l.              .oXK:
//       .KX;    .dNKoON0;lXNkcld0NXo::cd0NNO:;,,'.. .0Xc            lXXo..'l0NNKd,.              .c0Nk,
//       :XK.     .xNX0NKc.cXXl  ;KXl    .dN0.       .0No            .xNXOKNXOo,.               .l0Xk;.
//      .dXk.      .lKWN0d::OWK;  lXXc    .OX:       .ONx.     . .,cdk0XNXOd;.   .'''....;c:'..;xKXx,
//      .0No         .:dOKNNNWNKOxkXWXo:,,;ONk;,,,,,;c0NXOxxkO0XXNXKOdc,.  ..;::,...;lol;..:xKXOl.
//      ,XX:             ..';cldxkOO0inpKXXXXXXXXXXinpinpK00Okxdol:;'..   .';::,..':llc,..'linpXkc.
//      :NX'    .     ''            ..................             .,;:;,',;ccc;'..'linpX0d;.
//      lNK.   .;      ,lc,.         ................        ..,,;;;;;;:::,....,linpX0d:.
//     .oN0.    .'.      .;ccc;,'....              ....'',;;;;;;;;;;'..   .;oOXX0d:.
//     .dN0.      .;;,..       ....                ..''''''''....     .:dOinpko;.
//      lNK'         ..,;::;;,'.........................           .;d0X0kc'.
//      .xXO'                                                 .;oOK0x:.
//       .cinpo.                                    .,:oxinpkxk0K0xc'.
//         .oinpkc,.                         .';cok0XNNNX0Oxoc,.
//           .;d0XX0kdlc:;,,,',,,;;:clodkO0inp0Okdl:,'..
//               .,coxO0KXXXXXXXinp0OOxdoc:,..
//                         ...
 

/*
                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                    ___/`---'\___
                  .' \\|     |// '.
                 / \\|||  :  |||// \
                / _||||| -:- |||||- \
               |   | \\\  -  /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
             ___'. .'  /--.--\  `. .'___
          ."" '<  `.___\_<|>_/___.' >' "".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `_.   \_ __\ /__ _/   .-` /  /
     =====`-.____`.___ \_____/___.-`___.-'=====
                       `=---='
 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
  Sourav Verma IPG_2013  ABV_IIITMG Task @ Codechef/codeforces 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/   