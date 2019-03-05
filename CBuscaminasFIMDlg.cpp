/*el siguiente codigo pertece al codigo base del juego buscaminas 
desarrollado por Nilton Ramos Esteban como parte del curso de POO en 
la UNI,# ESPERO QUE LES INTERSE Y PUEDAN MEJORARLO */

void CBuscaminaFIMDlg::inicializar()
{srand(time(NULL));
 mi=10;ms=60;tc=18;n=20;m=25;
 int i,j,ii,jj,c;
 for (bomba = 0;bomba < m_CAJA;bomba++) // ponemos las bomba selecionando casillas de manera aleatoria 
	{
	 i = rand() % n;
	 j = rand() % m;

	 if (T[i][j] != 9)
		 T[i][j] = 9;
	 else
		 bomba=bomba-1;
	 }
 for (i = 0;i < n;i++) // rellenamos con valor cero las casillas sin bomba 
	 for (j = 0;j < m;j++)
	 {
		 if (T[i][j] != 9)
			 T[i][j] = 0;

		 V[i][j] = 0; 
	 }
 // esta seccion es para encontrar  el numero de bombas que tiene a su al rededor un casillero sin bomba
 for(i=0;i<n;i++)
	for(j=0;j<m;j++)
		if (T[i][j]==0)
		   {c=0;
			for(ii=i-1;ii<=i+1;ii++)
			  for(jj=j-1;jj<=j+1;jj++)
				 if((ii>=0 && ii <n) && (jj>=0 && jj <m))
				    if(T[ii][jj]==9)
					   c++;
			T[i][j]=c;
			}

}

void CBuscaminaFIMDlg::pintar()
{CClientDC g(this);
int RETORNA=0;
 CBrush fcas1,fcas2,fcas3,fcas4,fcas5,fcas6;
 CPen bcas,bcas2;
 CFont let1,let2,let3;
 CString str, clk,mensaje1,mensaje2,mensaje3,mensaje4;
 mensaje1 = "FELICITACIONES GANASTE    :) ";
 mensaje2 = "LAMENTABLEMETE PERDISTE  :'(";
 mensaje3 = "RESULTADO";

 let1.CreateFontW(25,0,0,0,0,0,0,0,0,0,0,0,0,_T("Times New Roman"));
 let2.CreateFontW(18,0,0,0,1,0,0,0,0,0,0,0,0,_T("Verdana"));
 let3.CreateFontW(18,0,0,0,1,0,0,0,0,0,0,0,0,_T("Arial"));
 fcas1.CreateSolidBrush(RGB(255, 231, 48 ));//
 fcas2.CreateSolidBrush(RGB(255, 255, 255));//
 fcas3.CreateSolidBrush(RGB(44, 142, 186));//
 fcas4.CreateSolidBrush(RGB(255, 0, 0));//
 fcas5.CreateSolidBrush(RGB(19, 193, 241));//
 fcas6.CreateSolidBrush(RGB(240,240, 240));
 bcas.CreatePen(BS_SOLID,1,RGB(0,0,255));// PS_DOT
 bcas2.CreatePen(BS_SOLID, 1, RGB(240, 240, 240));
 g.SelectObject(bcas);
 g.SetBkMode(TRANSPARENT); // Indica el tipo de fondo del texto TRANSPARENT u OPAQUE
 g.SetTextColor(RGB(255,0,0));
 g.SelectObject(let1);
 g.TextOutW( 10,10,_T("JUEGO DE BUSCAMINAS"));
 g.SelectObject(let2);
 g.SetTextColor(RGB(0,0,255));
 g.TextOutW( 10,40,_T("ESTADO:"));
 g.SetBkMode(OPAQUE);
 g.TextOutW(80, 40, _T("JUGANDO"));
 g.SetBkMode(TRANSPARENT);
 g.TextOutW( 250,40,_T("JUGADAS:"));
 g.SelectObject(let3);
 g.SetTextColor(RGB(34,250,60));
  clk.Format(_T("%d"), pix);                        // CAMBIA EL FORMATO DE LAS JUGADAS
 g.SetBkMode(OPAQUE);
 g.SelectObject(fcas6);
 g.SelectObject(bcas2);
 g.Rectangle(328,40,400,59);
 g.TextOutW(328, 40, clk);                         // IMPRIME LAS JUGADAS
 g.SetBkMode(TRANSPARENT);
 g.SetTextColor(RGB(0, 0, 0));
 int i,j;
 // EMPIEZA PINTANDO LA MATRIZ DE VISIVILIDAD O CONTROL DE VISTO 
  for(i=0;i<n;i++)
	for(j=0;j<m;j++)
  	  {if (V[i][j]==0) // V[i][j]=0 no visto,V[i][j]=1 visto
			g.SelectObject(fcas1); // SELECCIONA COLOR AMARILLO COMO FONDO 
	   else
			g.SelectObject(fcas2);	// SELECCIONA COLOR BLANCO COMO FONDO 
	   g.Rectangle(mi+j*tc,ms+i*tc,mi+(j+1)*tc,ms+(i+1)*tc); // CUBRE LA MATRIZ D ACUERDO A LO ANTERIOR 
	   if (V[i][j]==1 )	
	   {
		   //PERDISTE .................

		   if (T[i][j] == 9) // CUANDO EL CASILLERO DE UNA MATRIZ ES VISIBLE Y PARALELO A ELLO LA MATRIZ T ,TIENE UNA BOMBA 
		   {
			  for (i = 0;i < n;i++)
			   		   for (j = 0;j < m;j++)
				   {
					   g.SelectObject(fcas4); // PINTA DE COLOR ROJO TODO LOS CASILLEROSS
					   g.Rectangle(mi + j*tc, ms + i*tc, mi + (j + 1)*tc, ms + (i + 1)*tc);// DIBUJA LOS RECTANGULOS EN LA MATRIZ t
				   }
			   for (i = 0;i < n;i++)
				  for (j = 0;j < m;j++)
				  {
					  if (T[i][j] == 9 )
					 
					  g.TextOutW(mi + j*tc + 0.3*tc, ms + i*tc + 0.2*tc, _T("*"));// ESCRIBE EL ASTERISCO EN CASILLEROS CON EN T CUYOS VALORES 9
				  }
			   // ESCRIBIMOS LOS MENSAJES 
			  g.SetBkMode(OPAQUE);
			  g.SetTextColor(RGB(255, 0, 0));
			  g.TextOutW(80, 40, _T("PERDISTE"));
			  g.SelectObject(let1);
			  RETORNA=MessageBox(mensaje2, mensaje3, MB_OK | MB_ICONINFORMATION);
		   } 
		   // EN CASO DE QUE LOS VALORES DE T SON DISTINTO DE 9 Y 0

		  else if (T[i][j]>0 )
			{
			  str.Format(_T("%d"),T[i][j]); // IMPRIME LOS VALORES LOS VALORES DE BOMBAS AL REDEDOR DE UNA CASILLA 
			  g.TextOutW( mi+j*tc+0.25*tc,ms+i*tc+0.05*tc,str);
			}		 
		  	 
			   }
		}

  // GANASTE .........

  casillas = 0; // CONTADOR DE CASILLAS SIN LIBERAR 
  for (i = 0;i < n;i++)
	  for (j = 0;j < m;j++)

		  if (V[i][j] == 0)
			  casillas++;

  if (casillas == m_CAJA) // COMPARA CASILLEROS SIN DAR CLICK CON EL NUMERO DE BOMBAS INGRESADO EN LA CAJA 
  {

	  for (i = 0;i < n;i++)
		  for (j = 0;j < m;j++)
		  {

			  g.SelectObject(fcas5); // ELIGE FONDO CELESTE 
			  g.Rectangle(mi + j*tc, ms + i*tc, mi + (j + 1)*tc, ms + (i + 1)*tc);

			  if (T[i][j] == 9)
				  
				  g.TextOutW(mi + j*tc + 0.3*tc, ms + i*tc + 0.2*tc, _T("*"));// AGREGA LAS BOMBAS EN SUS CASILLAS INICIALES 
				 
		  }
	  g.SetBkMode(OPAQUE);
	  g.TextOutW(80, 40, _T("GANASTE"));
	  g.SelectObject(let1);
	  RETORNA=MessageBox(mensaje1, mensaje3, MB_OK | MB_ICONINFORMATION);
	 

	 
	  

  }
  if (RETORNA == 1) {
	  OnBnClickedButton1();
	  
  }

 }
void CBuscaminaFIMDlg::OnBnClickedButton1()
{
	UpdateData(true);
 int i, j;
 for (i = 0;i < n;i++)
	 for (j = 0;j < m;j++)
	 {
		 T[i][j] = 0;
	 }
 pix = 0;
 inicializar();
 pintar();
 UpdateData(false);
}



void CBuscaminaFIMDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	int i, j;
	i=(point.y-ms)/tc; j=(point.x-mi)/tc;
	if (i>=0 && i<n && j>=0 && j<m)
	{
	if (T[i][j] != 9 && V[i][j] == 0)
		pix++; // CONTADOR DE CLICKS
	if (T[i][j] == 0)
		liberar(i, j);// LIBERA LOS CONTORNOS 
	if (T[i][j] == 9)
	{
		if ( V[i][j] == 0)
		{
			pix = pix + 1; // SUMAMOS UN CLIK AL NUMERO DE JUGADAS AL ULTIMO NUMERO DE P
		}
		mostrartodo();
	}
		V[i][j] = 1; // PONE EN ESTADO VISTO A LA MATRIZ V
	}
	pintar();
CDialogEx::OnLButtonUp(nFlags, point);
}

void CBuscaminaFIMDlg::liberar(int i, int j)
{int ii,jj;
 V[i][j]=1;
 if (T[i][j]==0)
   for(ii=i-1;ii<=i+1;ii++)
	 for(jj=j-1;jj<=j+1;jj++)
	   if( (ii>=0 && ii<n) && (jj>=0 && jj<m)  
		 && !(ii==i && jj==j) && V[ii][jj]==0)
		 liberar(ii,jj);
}

void CBuscaminaFIMDlg::mostrartodo()
{int i,j;
 for(i=0;i<n;i++)
	for(j=0;j<m;j++)
		V[i][j]=1;

}

void CBuscaminaFIMDlg::OnEnChangeCaja()
{
	// TODO:  Si éste es un control RICHEDIT, el control no
	// enviará esta notificación a menos que se invalide CDialogEx::OnInitDialog()
	// función y llamada CRichEditCtrl().SetEventMask()
	// con la marca ENM_CHANGE ORed en la máscara.

	// TODO:  Agregue aquí el controlador de notificación de controles
}

