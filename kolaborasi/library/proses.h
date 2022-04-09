 using namespace std;

class Proses {
	public :
	  void cetak(){
		  cout<<"Anda sebagai proses\n";
  	}

    void getData(){
      ambil_data.open("api_data.txt");
      bool ayam_gr = true;
      bool ayam_gp = true;
      bool udang_gr;
      bool cumi_gr;
      while(!ambil_data.eof()){
        if(ayam_gp){
            ambil_data>>bnyk_aymGp;
            ayam_gp=false;
          }
          else if (ayam_gr){
            ambil_data>>bnyk_aymGr;
            ayam_gr=false;
          }
          else if(udang_gr){
            ambil_data>>bnyk_udngGr;
            udang_gr=false;
          }
          else if (cumi_gr){
            ambil_data>>bnyk_cumiGr;
            cumi_gr=false;
          }
          else{
            ambil_data>>bnyk_ayamBk;
          }
      }
      ambil_data.close();
    }

  void toFile (){
    int total = (hrg_ayamGp * bnyk_aymGp) + (hrg_aymGr * bnyk_aymGr) + (hrg_udngGr * bnyk_udngGr) + (hrg_cumiGr * bnyk_cumiGr) + (hrg_ayamBk * bnyk_ayamBk);
    float batas = 45000;
    float biaya_ongkir=15000;
    float t2 = float(total);

    if (total >= batas)
      t2 = t2+biaya_ongkir ;

    tulis_data.open("api_data.txt");
    tulis_data << total << endl;
    tulis_data << biaya_ongkir << endl;
		tulis_data << t2 << endl;
		tulis_data << bnyk_aymGp << endl;
		tulis_data << bnyk_aymGr << endl;
    tulis_data << bnyk_udngGr << endl;
    tulis_data << bnyk_cumiGr << endl;
    tulis_data << bnyk_ayamBk;
    tulis_data.close(); 
    }
  
  private :
    ifstream ambil_data;
    ofstream tulis_data;
    int bnyk_aymGp;
    int bnyk_aymGr;
    int bnyk_udngGr;
    int bnyk_cumiGr;
    int bnyk_ayamBk;
    int hrg_ayamGp = 21000;
    int hrg_aymGr = 17000;
    int hrg_udngGr = 19000;
    int hrg_cumiGr = 20000;
    int hrg_ayamBk = 25000;
    float biaya_ongkir;
}; 