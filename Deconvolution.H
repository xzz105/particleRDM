
int* cells = new int[OF_nCells*6];
int* faces = new int[OF_nFaces*4];
double* vert = new double[OF_nPoints*3];

long ii, jj;
//set up cv-face
for (ii=0; ii< OF_nCells; ii++)
{
   for (jj=0; jj< 6; jj++) 
   {
   cells[ii*6+jj] = OF_cellFace[ii][jj];
//   Info<<"cells"<<cells[ii*6+jj]<<endl;
   }
}
//set up face-vert
for (ii=0; ii< OF_nFaces; ii++)
{
   for (jj=0; jj< 4; jj++) 
   {
   faces[ii*4+jj] = OF_faceVert[ii][jj];
//   Info<<"faces"<<faces[ii*4+jj]<<endl;
   }
}
//set up vert coord
for (ii=0; ii< OF_nPoints; ii++)
{
   for (jj=0; jj< 3; jj++) 
   {
   vert[ii*3+jj] = OF_meshPoints[ii][jj];
//   Info<<"verts"<<vert[ii*3+jj]<<endl;
   }
}

Info<<" RDM init done."<<endl;


RDM::Deconv* rdm;
rdm = new RDM::HexDeconv(OF_nPoints,OF_nFaces,OF_nCells,vert,faces,cells);
