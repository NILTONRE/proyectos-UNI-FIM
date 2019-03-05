class CBuscaminaFIMDlg : public CDialogEx
{
// Construcción
public:
	CBuscaminaFIMDlg(CWnd* pParent = NULL);	// Constructor estándar

// Datos del cuadro de diálogo
	enum { IDD = IDD_BUSCAMINAFIM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV
int T[100][100],V[100][100];
int n,m,mi,ms,tc,pix=0,bomba=0,casillas;
void inicializar();
void pintar();
void liberar(int i, int j);
void mostrartodo();
//void ganate();
//void perdiste();

// Implementación
protected:
