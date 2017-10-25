//definition of points
//float x, y, z;


Info<<"after constructing the object"<<endl;
double* poi = new double[3];
poi[0] = 0.00181818;
poi[1] = 0.055;
poi[2] = 0.00181818; 
Info<<"after setting the point"<<endl;
//vector position(p, 0.123, 8.12); 
//label celli = mesh.findCell(position);
point location(poi[0], poi[1], poi[2]);
label ID=mesh.findCell(location); 

double* ubar = new double[OF_nCells];
UList<scalar> OF_velocity = U.component(vector::X);
//ubar = U.component(vector::X) 
forAll(OF_velocity,celli)
{
	ubar[celli]=OF_velocity[celli];
}
Info<<"After getting the velocity"<<OF_nCells<<endl;
/*double* q_ = new double[3];
std::vector<double> x_= rdm->QuadraturePoints(OF_nCells);
    // get the quadrature points and perform deconvolution 
    int cnt = 0;
    for (int i = 0; i < OF_nCells; i++) {
        // quadrature points for cv[i]
         x_ = rdm->QuadraturePoints(i);
        // deconvolved results at each points in x_
        int npt = x_.size() / 3;
        double res = 0.0;
        for (int ino = 0; ino < npt; ino++) {
            q_[0] = x_[ino*3+0]; q_[1] = x_[ino*3+1]; q_[2] = x_[ino*3+2]; 
            res += rdm->PointDeconv(i, q_, ubar);
        }
            res /= 6.0;
        if (abs(res - ubar[i]) > 1.0e-10) {
            Info << " Mean value at CV " << i << " mismatch by " << res - ubar[i] << endl;
            cnt++;
        }
    }
    if (cnt == 0) Info << " Correctness test passed. " <<endl;
*/
int i = 605;
double u_deconv=0.0;
u_deconv = rdm->PointDeconv(i, poi, ubar);
Info<<"After deconvoluation"<<ID<<"guess"<<i<<endl;

Info<<u_deconv<<"compare"<<ubar[ID]<<ubar[i]<<endl;
