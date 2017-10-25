// This file gathers all the mesh information that is required by the PMC module.

//labels are declared in Init_PMC
Info<<"get_OF_mesh_data: getting mesh vars"<<endl;

long OF_nCells = mesh.nCells();                   //  Number of cells
Info<<"get_OF_mesh/ OF_nCells: "<<OF_nCells<<endl;
long OF_nPoints = mesh.nPoints();                 // Number of vertices
Info<<"get_OF_mesh/ OF_nPoints: "<<OF_nPoints<<endl;

long OF_nIntFaces = mesh.nInternalFaces();        // Number of internal faces

long OF_nFaces = mesh.nFaces();                   // Number of faces in OpenFOAM
Info<<"get_OF_mesh/ OF_nFaces: "<<OF_nFaces<<endl;


long OF_nTotFaces = 6*OF_nCells;                  // Total number of faces. Hard coded
                                                   // as 6 times the number of cells i.e.,
                                                   //  all the cells are assumed to be hexahdral.
                                                   // INTERNAL FACES ARE COUNTED TWICE HERE.


long OF_nVertCell = 8;                            // Number of vertices for each cell. hard coded to 8.

long OF_nVertFace = 4;                            // Number of vertices for each face. hard coded to 4.

long OF_nFaceCell = 6;                            // Number of faces for each cell. hard coded to 6.


UList<vector> OF_meshPoints = mesh.points();       // vertices coordinates

UList<scalar> OF_cellVolumes = mesh.cellVolumes(); //  cell volumes

UList<vector> OF_cellCenters = mesh.cellCentres(); //  cell centers

UList<vector> OF_faceCenters = mesh.faceCentres(); //  face centers

UList<vector> OF_faceAreas = mesh.faceAreas();     //  face areas (area components in x,y and z directions)

UList<face>  OF_faceVert = mesh.faces();           //  ordered vertices for faces

UList<cellShape> OF_cellVert = mesh.cellShapes();  // ordered set of vertices for cells

labelList  OF_faceOwner = mesh.faceOwner();        //  owner cell indices for all the faces

labelList OF_faceNeighbour = mesh.faceNeighbour(); // Neighbour cell indices for all the internal faces

//  standard OpenFOAM format data not accessible for ordered set of faces for cells.
//  Therefore, accessing that data into a 2D integer array.
int **OF_cellFace;
OF_cellFace = new int*[OF_nCells];
forAll(mesh.cells(),snI)
{
  labelList test= mesh.cellShapes()[snI].meshFaces(mesh.faces(),mesh.cells()[snI]);
  OF_cellFace[snI] = new int [OF_nFaceCell];
  forAll(test,snII)
  {
    OF_cellFace[snI][snII]=  test[snII];
  }
}
//  data accessed for ordered set of faces for all cells into OF_cellFace
//

//UList<vector> OF_meshPoints = mesh.points();  // vertices coordinates
//int nCells = OF_nCells;
//int nPoints = OF_nPoints;

Info<<"OF_faceVert"<<OF_faceVert[0].begin()<<endl;
Info<<"OF_cellFace"<<OF_cellFace[10][2]<<endl;

