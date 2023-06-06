#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

struct Node
{
    string name;
    string line;
    Node *transfer_1;
    Node *transfer_2;
    Node *transfer_3;
    Node *transfer_4;
    Node *transfer_5;
    Node(string name, string line) : name(name), line(line), transfer_1(NULL), transfer_2(NULL), transfer_3(NULL), transfer_4(NULL), transfer_5(NULL) {}
};

typedef pair<int, Node *> pin; // pair of (weight, node)

vector<string> dijkstra_shortest_path(vector<Node *> graph, string start, string end)
{
    vector<int> distances(graph.size(), numeric_limits<int>::max());
    vector<string> previous(graph.size(), "");
    priority_queue<pin, vector<pin>, greater<pin>> pq;

    int startIdx, endIdx;
    for (int i = 0; i < graph.size(); ++i)
    {
        if (graph[i]->name == start)
            startIdx = i;
        if (graph[i]->name == end)
            endIdx = i;
    }

    distances[startIdx] = 0;
    pq.push(make_pair(0, graph[startIdx]));

    while (!pq.empty())
    {
        int current_distance = pq.top().first;
        Node *current_node = pq.top().second;
        pq.pop();

        if (current_node->name == end)
        {
            break;
        }

        if (current_distance > distances[current_node - graph[0]])
        {
            continue;
        }

        if (current_node->transfer_1 != NULL)
        {
            int weight = 1; // Assuming equal weight for all connections
            int distance = current_distance + weight;
            int neighborIdx = current_node->transfer_1 - graph[0];

            if (distance < distances[neighborIdx - 1])
            {
                distances[neighborIdx - 1] = distance;
                previous[neighborIdx - 1] = current_node->name;
                pq.push(make_pair(distance, current_node->transfer_1));
            }
        }

        if (current_node->transfer_2 != NULL)
        {
            int weight = 1; // Assuming equal weight for all connections
            int distance = current_distance + weight;
            int neighborIdx = current_node->transfer_2 - graph[0];

            if (distance < distances[neighborIdx - 1])
            {
                distances[neighborIdx - 1] = distance;
                previous[neighborIdx - 1] = current_node->name;
                pq.push(make_pair(distance, current_node->transfer_2));
            }
        }

        if (current_node->transfer_3 != NULL)
        {
            int weight = 1; // Assuming equal weight for all connections
            int distance = current_distance + weight;
            int neighborIdx = current_node->transfer_3 - graph[0];

            if (distance < distances[neighborIdx - 1])
            {
                distances[neighborIdx - 1] = distance;
                previous[neighborIdx - 1] = current_node->name;
                pq.push(make_pair(distance, current_node->transfer_3));
            }
        }
        if (current_node->transfer_4 != NULL)
        {
            int weight = 1; // Assuming equal weight for all connections
            int distance = current_distance + weight;
            int neighborIdx = current_node->transfer_4 - graph[0];

            if (distance < distances[neighborIdx - 1])
            {
                distances[neighborIdx - 1] = distance;
                previous[neighborIdx - 1] = current_node->name;
                pq.push(make_pair(distance, current_node->transfer_3));
            }
        }
        if (current_node->transfer_5 != NULL)
        {
            int weight = 1; // Assuming equal weight for all connections
            int distance = current_distance + weight;
            int neighborIdx = current_node->transfer_5 - graph[0];

            if (distance < distances[neighborIdx - 1])
            {
                distances[neighborIdx - 1] = distance;
                previous[neighborIdx - 1] = current_node->name;
                pq.push(make_pair(distance, current_node->transfer_3));
            }
        }
    }

    vector<string> path;
    int currentIdx = endIdx;
    while (currentIdx >= 0)
    {
        path.insert(path.begin(), graph[currentIdx]->name);
        currentIdx = graph[currentIdx]->name == start ? -1 : currentIdx - 1;
    }

    return path;
}

int main()
{
    vector<Node *> graph;

    // Create the nodes for the subway stations
    // Línea 1
    Node *nodeObservatorio = new Node("Observatorio", "Linea 1");
    Node *nodeTacubayaLinea1 = new Node("Tacubaya", "Linea 1");
    Node *nodeJuanacatlan = new Node("Juanacatlan", "Linea 1");
    Node *nodeChapultepec = new Node("Chapultepec", "Linea 1");
    Node *nodeSevilla = new Node("Sevilla", "Linea 1");
    Node *nodeInsurgentes = new Node("Insurgentes", "Linea 1");
    Node *nodeCuauhtemoc = new Node("Cuauhtemoc", "Linea 1");
    Node *nodeBalderas = new Node("Balderas", "Linea 1");
    Node *nodeSaltoDelAgua = new Node("Salto del Agua", "Linea 1");
    Node *nodeIsabelLaCatolica = new Node("Isabel la Catolica", "Linea 1");
    Node *nodePinoSuarez = new Node("Pino Suarez", "Linea 1");
    Node *nodeMerced = new Node("Merced", "Linea 1");
    Node *nodeCandelaria = new Node("Candelaria", "Linea 1");
    Node *nodeSanLazaro = new Node("San Lazaro", "Linea 1");
    Node *nodeMoctezuma = new Node("Moctezuma", "Linea 1");
    Node *nodeBalbuena = new Node("Balbuena", "Linea 1");
    Node *nodeBoulevardPtoAereo = new Node("Boulevard Pto. Aereo", "Linea 1");
    Node *nodeGomezFarias = new Node("Gomez Farias", "Linea 1");
    Node *nodeZaragoza = new Node("Zaragoza", "Linea 1");
    Node *nodePantitlanLinea1 = new Node("Pantitlan", "Linea 1");

    // Línea 5
    Node *nodePantitlanLinea5 = new Node("Pantitlan", "Linea 5");
    Node *nodeHangares = new Node("Hangares", "Linea 5");
    Node *nodeTerminalAerea = new Node("Terminal Aerea", "Linea 5");
    Node *nodeOceania = new Node("Oceania", "Linea 5");
    Node *nodeAragon = new Node("Aragon", "Linea 5");
    Node *nodeEduardoMolina = new Node("Eduardo Molina", "Linea 5");
    Node *nodeConsulado = new Node("Consulado", "Linea 5");
    Node *nodeValleGomez = new Node("Valle Gomez", "Linea 5");
    Node *nodeMisterios = new Node("Misterios", "Linea 5");
    Node *nodeLaRaza = new Node("La Raza", "Linea 5");
    Node *nodeAutobusesdelNorte = new Node("Autobuses del Norte", "Linea 5");
    Node *nodeInstitutodelPetroleo = new Node("Instituto del Petroleo", "Linea 5");
    Node *nodePolitecnico = new Node("Politecnico", "Linea 5");

    // Línea 9
    Node *nodeTacubayaLinea9 = new Node("Tacubaya", "Linea 9");
    Node *nodePatriotismo = new Node("Patriotismo", "Linea 9");
    Node *nodeChilpancingo = new Node("Chilpancingo", "Linea 9");
    Node *nodeCentroMedico = new Node("Centro Medico", "Linea 9");
    Node *nodeLazaroCardenas = new Node("Lazaro Cardenas", "Linea 9");
    Node *nodeChabacanoLinea9 = new Node("Chabacano", "Linea 9");
    Node *nodeJamaica = new Node("Jamaica", "Linea 9");
    Node *nodeMixiuhca = new Node("Mixiuhca", "Linea 9");
    Node *nodeVelodromo = new Node("Velodromo", "Linea 9");
    Node *nodeCiudadDeportiva = new Node("Ciudad Deportiva", "Linea 9");
    Node *nodePuebla = new Node("Puebla", "Linea 9");
    Node *nodePantitlanLinea9 = new Node("Pantitlan", "Linea 9");

    // Línea 8
    Node *nodeGaribaldi = new Node("Garibaldi", "Linea 8");
    Node *nodeBellasArtes = new Node("Bellas Artes", "Linea 8");
    Node *nodeSanJuanDeLetran = new Node("San Juan De Letran", "Linea 8");
    Node *nodeSaltoDelAguaLinea8 = new Node("Salto del Agua", "Linea 8");
    Node *nodeDoctores = new Node("Doctores", "Linea 8");
    Node *nodeObrera = new Node("Obrera", "Linea 8");
    Node *nodeChabacanoLinea8 = new Node("Chabacano", "Linea 8");
    Node *nodeLaViga = new Node("La Viga", "Linea 8");
    Node *nodeSantaAnita = new Node("Santa Anita", "Linea 8");
    Node *nodeCoyuya = new Node("Coyuya", "Linea 8");
    Node *nodeIztacalco = new Node("Iztacalco", "Linea 8");
    Node *nodeApatlaco = new Node("Apatlaco", "Linea 8");
    Node *nodeAculco = new Node("Aculco", "Linea 8");
    Node *nodeEscuadron201 = new Node("Escuadron 201", "Linea 8");
    Node *nodeAtlalilcoLinea8 = new Node("Atlalilco", "Linea 8");
    Node *nodeIztapalapa = new Node("Iztapalapa", "Linea 8");
    Node *nodeCerrodelaEstrella = new Node("Cerro de la Estrella", "Linea 8");
    Node *nodeUAMIztapalapa = new Node("UAM Iztapalapa", "Linea 8");
    Node *nodeConstitucionde1917 = new Node("Constitucion de 1917", "Linea 8");

    // Línea 12
    Node *nodeMixcoacLinea12 = new Node("Mixcoac", "Linea 12");
    Node *nodeInsurgentesSur = new Node("Insurgentes Sur", "Linea 12");
    Node *nodeHospital20DeNoviembre = new Node("Hospital 20 de Noviembre", "Linea 12");
    Node *nodeZapata = new Node("Zapata", "Linea 12");
    Node *nodeParqueDeLosVenados = new Node("Parque de Los Venados", "Linea 12");
    Node *nodeEjeCentral = new Node("EjeCentral", "Linea 12");
    Node *nodeErmitaLinea12 = new Node("Ermita", "Linea 12");
    Node *nodeMexicaltzingo = new Node("Mexicaltzingo", "Linea 12");
    Node *nodeAtlalilcoLinea12 = new Node("Atlalilco", "Linea 12");
    Node *nodeEjeCentral = new Node("EjeCentral", "Linea 12");
    Node *nodeCulhuacan = new Node("Culhuacan", "Linea 12");
    Node *nodeSanAndresTomatlan = new Node("San Andres Tomatlan", "Linea 12");
    Node *nodeLomasEstrella = new Node("Lomas Estrella", "Linea 12");
    Node *nodeCalle11 = new Node("Calle 11", "Linea 12");
    Node *nodePerifericoOriente = new Node("Periferico Oriente", "Linea 12");
    Node *nodeTezonco = new Node("Tezonco", "Linea 12");
    Node *nodeOlivos = new Node("Olivos", "Linea 12");
    Node *nodeNopalera = new Node("Nopalera", "Linea 12");
    Node *nodeZapotitlan = new Node("Zapotitlan", "Linea 12");
    Node *nodeTlaltenco = new Node("Tlaltenco", "Linea 12");
    Node *nodeTlahuac = new Node("Tlahuac", "Linea 12");
    // Línea 2
    Node *nodeCuatroCaminos = new Node("Cuatro Caminos", "Linea 2");
    Node *nodePanteones = new Node("Panteones", "Linea 2");
    Node *nodeTacubaLinea2 = new Node("Tacuba", "Linea 2");
    Node *nodeCuitlahuac = new Node("Cuitlahuac", "Linea 2");
    Node *nodePopotla = new Node("Popotla", "Linea 2");
    Node *nodeColegioMilitar = new Node("Colegio Militar", "Linea 2");
    Node *nodeNormal = new Node("Normal", "Linea 2");
    Node *nodeSanCosme = new Node("San Cosme", "Linea 2");
    Node *nodeRevolucion = new Node("Revolucion", "Linea 2");
    Node *nodeHidalgoLinea2 = new Node("Hidalgo", "Linea 2");
    Node *nodeBellasArtesLinea2 = new Node("Bellas Artes", "Linea 2");
    Node *nodeAllende = new Node("Allende", "Linea 2");
    Node *nodeZocalo = new Node("Zocalo", "Linea 2");
    Node *nodePinoSuarezLinea2 = new Node("Pino Suarez", "Linea 2");
    Node *nodeSanAntonioAbad = new Node("San Antonio Abad", "Linea 2");
    Node *nodeChabacanoLinea2 = new Node("Chabacano", "Linea 2");
    Node *nodeViaducto = new Node("Viaducto", "Linea 2");
    Node *nodeXola = new Node("Xola", "Linea 2");
    Node *nodeVillaDeCortes = new Node("Villa de Cortes", "Linea 2");
    Node *nodeNativitas = new Node("Nativitas", "Linea 2");
    Node *nodePortales = new Node("Portales", "Linea 2");
    Node *nodeErmita = new Node("Ermita", "Linea 2");
    Node *nodeGeneralAnaya = new Node("General Anaya", "Linea 2");
    Node *nodeTasquena = new Node("Tasquena", "Linea 2");

    // Línea 3
    Node *nodeIndiosVerdes = new Node("Indios Verdes", "Linea 3");
    Node *nodeDeportivo18DeMarzo = new Node("Deportivo 18 de Marzo", "Linea 3");
    Node *nodePotrero = new Node("Potrero", "Linea 3");
    Node *nodeLaRaza = new Node("La Raza", "Linea 3");
    Node *nodeTlatelolco = new Node("Tlatelolco", "Linea 3");
    Node *nodeGuerreroLinea3 = new Node("Guerrero", "Linea 3");
    Node *nodeHidalgoLinea3 = new Node("Hidalgo", "Linea 3");
    Node *nodeJuarez = new Node("Juarez", "Linea 3");
    Node *nodeBalderasLinea3 = new Node("Balderas", "Linea 3");
    Node *nodeNiñosHeroes = new Node("Ninos Heroes", "Linea 3");
    Node *nodeHospitalGeneral = new Node("Hospital General", "Linea 3");
    Node *nodeCentroMedicoLinea3 = new Node("Centro Medico", "Linea 3");
    Node *nodeEtiopia = new Node("Etiopia", "Linea 3");
    Node *nodeEugenia = new Node("Eugenia", "Linea 3");
    Node *nodeDivisionDelNorte = new Node("Division del Norte", "Linea 3");
    Node *nodeZapataLinea3 = new Node("Zapata", "Linea 3");
    Node *nodeCoyoacan = new Node("Coyoacan", "Linea 3");
    Node *nodeViveros = new Node("Viveros", "Linea 3");
    Node *nodeMiguelAngeldeQuevedo = new Node("Miguel Angel de Quevedo", "Linea 3");
    Node *nodeCopilco = new Node("Copilco", "Linea 3");
    Node *nodeUniversidad = new Node("Universidad", "Linea 3");
    // Línea 7
    Node *nodeElRosarioLinea7 = new Node("El Rosario", "Linea 7");
    Node *nodeAquilesSerdan = new Node("Aquiles Serdan", "Linea 7");
    Node *nodeCamarones = new Node("Camarones", "Linea 7");
    Node *nodeRefineria = new Node("Refineria", "Linea 7");
    Node *nodeTacubaLinea7 = new Node("Tacuba", "Linea 7");
    Node *nodeSanJoaquin = new Node("San Joaquin", "Linea 7");
    Node *nodePolanco = new Node("Polanco", "Linea 7");
    Node *nodeAuditorio = new Node("Auditorio", "Linea 7");
    Node *nodeConstituyentes = new Node("Constituyentes", "Linea 7");
    Node *nodeTacubayaLinea7 = new Node("Tacubaya", "Linea 7");
    Node *nodeSanPedrodelosPinos = new Node("San Pedro de los Pinos", "Linea 7");
    Node *nodeSanAntonio = new Node("San Antonio", "Linea 7");
    Node *nodeMixcoacLinea7 = new Node("Mixcoac", "Linea 7");
    Node *nodeBarrancadelMuerto = new Node("BarrancadelMuerto", "Linea 7");
    // Línea 6
    Node *nodeElRosarioLinea6 = new Node("El Rosario", "Linea 6");
    Node *nodeTezozomoc = new Node("Tezozomoc", "Linea 6");
    Node *nodeAzcapotzalco = new Node("Azcapotzalco", "Linea 6");
    Node *nodeFerreria = new Node("Ferreria", "Linea 6");
    Node *nodeNorte45 = new Node("Norte 45", "Linea 6");
    Node *nodeVallejo = new Node("Vallejo", "Linea 6");
    Node *nodeInstitutoDelPetroleoLinea6 = new Node("Instituto del Petroleo", "Linea 6");
    Node *nodeLindavista = new Node("Lindavista", "Linea 6");
    Node *nodeDeportivo24DeFebrero = new Node("Deportivo 24 de Febrero", "Linea 6");
    Node *nodeLaVillaBasílica = new Node("La Villa Basílica", "Linea 6");
    Node *nodeMartinCarreraLinea6 = new Node("MartinCarrera", "Linea 6");
    // Línea 4
    Node *nodeMartínCarreraLinea4 = new Node("Martin Carrera", "Linea 4");
    Node *nodeTalisman = new Node("Talisman", "Linea 4");
    Node *nodeBondojito = new Node("Bondojito", "Linea 4");
    Node *nodeConsuladoLinea4 = new Node("Consulado", "Linea 4");
    Node *nodeCanalDelNorte = new Node("Canal del Norte", "Linea 4");
    Node *nodeMorelosLinea4 = new Node("Morelos", "Linea 4");
    Node *nodeCandelariaLinea4 = new Node("Candelaria", "Linea 4");
    Node *nodeFrayServando = new Node("Fray Servando", "Linea 4");
    Node *nodeJamaicaLinea4 = new Node("Jamaica", "Linea 4");
    Node *nodeSantaAnita = new Node("Santa Anita", "Linea 4");
    // Línea B
    Node *nodeBuenavista = new Node("Buenavista", "Linea B");
    Node *nodeGuerreroLineaB = new Node("Guerrero", "Linea B");
    Node *nodeGaribaldiLineaB = new Node("Garibaldi", "Linea B");
    Node *nodeLagunilla = new Node("Lagunilla", "Linea B");
    Node *nodeTepito = new Node("Tepito", "Linea B");
    Node *nodeMorelosLineaB = new Node("Morelos", "Linea B");
    Node *nodeSanLazaroLineaB = new Node("San Lazaro", "Linea B");
    Node *nodeRicardoFloresMagon = new Node("Ricardo Flores Magon", "Linea B");
    Node *nodeRomeroRubio = new Node("Romero Rubio", "Linea B");
    Node *nodeOceaniaLineaB = new Node("Oceania", "Linea B");
    Node *nodeDeportivoOceania = new Node("Deportivo Oceania", "Linea B");
    Node *nodeBosquedeAragon = new Node("Bosque de Aragon", "Linea B");
    Node *nodeVilladeAragon = new Node("Villa de Aragon", "Linea B");
    Node *nodeNezahualcoyotl = new Node("Nezahualcoyotl", "Linea B");
    Node *nodeImpulsora = new Node("Impulsora", "Linea B");
    Node *nodeRiodelosRemedios = new Node("RiodelosRemedios", "Linea B");
    Node *nodeMuzquiz = new Node("Muzquiz", "Linea B");
    Node *nodeEcatepec = new Node("Ecatepec", "Linea B");
    Node *nodeOlimpica = new Node("Olimpica", "Linea B");
    Node *nodePlazaAragon = new Node("Plaza Aragon", "Linea B");
    Node *nodeCiudadAzteca = new Node("Ciudad Azteca", "Linea B");

    // Define las conexiones entre los nodos
    // Línea 1
    nodeObservatorio->transfer_1 = nodeTacubayaLinea1;
    nodeTacubayaLinea1->transfer_1 = nodeObservatorio;
    nodeTacubayaLinea1->transfer_2 = nodeJuanacatlan;
    nodeJuanacatlan->transfer_1 = nodeTacubaya;
    nodeJuanacatlan->transfer_2 = nodeChapultepec;
    nodeChapultepec->transfer_1 = nodeJuanacatlan;
    nodeChapultepec->transfer_2 = nodeSevilla;
    nodeSevilla->transfer_1 = nodeChapultepec;
    nodeSevilla->transfer_2 = nodeInsurgentes;
    nodeInsurgentes->transfer_1 = nodeSevilla;
    nodeInsurgentes->transfer_2 = nodeCuauhtemoc;
    nodeCuauhtemoc->transfer_1 = nodeInsurgentes;
    nodeCuauhtemoc->transfer_2 = nodeBalderas;
    nodeBalderas->transfer_1 = nodeCuauhtemoc;
    nodeBalderas->transfer_2 = nodeSaltoDelAgua;
    nodeSaltoDelAgua->transfer_1 = nodeBalderas;
    nodeSaltoDelAgua->transfer_2 = nodeIsabelLaCatolica;
    nodeIsabelLaCatolica->transfer_1 = nodeSaltoDelAgua;
    nodeIsabelLaCatolica->transfer_2 = nodePinoSuarez;
    nodePinoSuarez->transfer_1 = nodeIsabelLaCatolica;
    nodePinoSuarez->transfer_2 = nodeMerced;
    nodeMerced->transfer_1 = nodePinoSuarez;
    nodeMerced->transfer_2 = nodeCandelaria;
    nodeCandelaria->transfer_1 = nodeMerced;
    nodeCandelaria->transfer_2 = nodeSanLazaro;
    nodeSanLazaro->transfer_1 = nodeCandelaria;

    // Línea 5
    nodePantitlan->transfer_1 = nodeHangares;
    nodeHangares->transfer_1 = nodePantitlan;
    nodeHangares->transfer_2 = nodeTerminalAerea;
    nodeTerminalAerea->transfer_1 = nodeHangares;
    nodeTerminalAerea->transfer_2 = nodeOceanologia;
    nodeOceanologia->transfer_1 = nodeTerminalAerea;
    nodeOceanologia->transfer_2 = nodeAragon;
    nodeAragon->transfer_1 = nodeOceanologia;
    nodeAragon->transfer_2 = nodeEduardoMolina;
    nodeEduardoMolina->transfer_1 = nodeAragon;
    nodeEduardoMolina->transfer_2 = nodeConsulado;
    nodeConsulado->transfer_1 = nodeEduardoMolina;
    nodeConsulado->transfer_2 = nodeVallejo;
    nodeVallejo->transfer_1 = nodeConsulado;

    // Línea 9
    nodeTacubaya2->transfer_1 = nodePatriotismo;
    nodePatriotismo->transfer_1 = nodeTacubaya2;
    nodePatriotismo->transfer_2 = nodeChilpancingo;
    nodeChilpancingo->transfer_1 = nodePatriotismo;
    nodeChilpancingo->transfer_2 = nodeCentroMedico;
    nodeCentroMedico->transfer_1 = nodeChilpancingo;
    nodeCentroMedico->transfer_2 = nodeLazaroCardenas;
    nodeLazaroCardenas->transfer_1 = nodeCentroMedico;
    nodeLazaroCardenas->transfer_2 = nodeChabacano;
    nodeChabacano->transfer_1 = nodeLazaroCardenas;
    nodeChabacano->transfer_2 = nodeJamaica;
    nodeJamaica->transfer_1 = nodeChabacano;

    // Línea 8
    nodeGaribaldi->transfer_1 = nodeBellasArtes;
    nodeBellasArtes->transfer_1 = nodeGaribaldi;
    nodeBellasArtes->transfer_2 = nodeSanJuanDeLetran;
    nodeSanJuanDeLetran->transfer_1 = nodeBellasArtes;
    nodeSanJuanDeLetran->transfer_2 = nodeSaltoDelAgua2;
    nodeSaltoDelAgua2->transfer_1 = nodeSanJuanDeLetran;
    nodeSaltoDelAgua2->transfer_2 = nodeDoctores;
    nodeDoctores->transfer_1 = nodeSaltoDelAgua2;
    nodeDoctores->transfer_2 = nodeObrera;
    nodeObrera->transfer_1 = nodeDoctores;
    nodeObrera->transfer_2 = nodeChabacano2;
    nodeChabacano2->transfer_1 = nodeObrera;
    nodeChabacano2->transfer_2 = nodeLaViga;
    nodeLaViga->transfer_1 = nodeChabacano2;

    // Línea 12
    nodeMixcoac->transfer_1 = nodeInsurgentesSur;
    nodeInsurgentesSur->transfer_1 = nodeMixcoac;
    nodeInsurgentesSur->transfer_2 = nodeHospital20DeNoviembre;
    nodeHospital20DeNoviembre->transfer_1 = nodeInsurgentesSur;
    nodeHospital20DeNoviembre->transfer_2 = nodeZapata;
    nodeZapata->transfer_1 = nodeHospital20DeNoviembre;
    nodeZapata->transfer_2 = nodeParqueDeLosVenados;
    nodeParqueDeLosVenados->transfer_1 = nodeZapata;

    // Línea 2
    nodeCuatroCaminos->transfer_1 = nodePanteones;
    nodePanteones->transfer_1 = nodeCuatroCaminos;
    nodePanteones->transfer_2 = nodeTacuba;
    nodeTacuba->transfer_1 = nodePanteones;
    nodeTacuba->transfer_2 = nodeCuitlahuac;
    nodeCuitlahuac->transfer_1 = nodeTacuba;
    nodeCuitlahuac->transfer_2 = nodePopotla;
    nodePopotla->transfer_1 = nodeCuitlahuac;
    nodePopotla->transfer_2 = nodeColegioMilitar;
    nodeColegioMilitar->transfer_1 = nodePopotla;
    nodeColegioMilitar->transfer_2 = nodeNormal;
    nodeNormal->transfer_1 = nodeColegioMilitar;
    nodeNormal->transfer_2 = nodeSanCosme;
    nodeSanCosme->transfer_1 = nodeNormal;
    nodeSanCosme->transfer_2 = nodeRevolucion;
    nodeRevolucion->transfer_1 = nodeSanCosme;
    nodeRevolucion->transfer_2 = nodeHidalgo;
    nodeHidalgo->transfer_1 = nodeRevolucion;
    nodeHidalgo->transfer_2 = nodeBellasArtes2;
    nodeBellasArtes2->transfer_1 = nodeHidalgo;
    nodeBellasArtes2->transfer_2 = nodeAllende;
    nodeAllende->transfer_1 = nodeBellasArtes2;
    nodeAllende->transfer_2 = nodeZocalo;
    nodeZocalo->transfer_1 = nodeAllende;
    nodeZocalo->transfer_2 = nodePinoSuarez2;
    nodePinoSuarez2->transfer_1 = nodeZocalo;
    nodePinoSuarez2->transfer_2 = nodeSanAntonioAbad;
    nodeSanAntonioAbad->transfer_1 = nodePinoSuarez2;
    nodeSanAntonioAbad->transfer_2 = nodeChabacano3;
    nodeChabacano3->transfer_1 = nodeSanAntonioAbad;
    nodeChabacano3->transfer_2 = nodeViaducto;
    nodeViaducto->transfer_1 = nodeChabacano3;
    nodeViaducto->transfer_2 = nodeXola;
    nodeXola->transfer_1 = nodeViaducto;
    nodeXola->transfer_2 = nodeVillaDeCortes;
    nodeVillaDeCortes->transfer_1 = nodeXola;
    nodeVillaDeCortes->transfer_2 = nodeNativitas;
    nodeNativitas->transfer_1 = nodeVillaDeCortes;
    nodeNativitas->transfer_2 = nodePortales;
    nodePortales->transfer_1 = nodeNativitas;
    nodePortales->transfer_2 = nodeErmita;
    nodeErmita->transfer_1 = nodePortales;
    nodeErmita->transfer_2 = nodeGeneralAnaya;
    nodeGeneralAnaya->transfer_1 = nodeErmita;
    nodeGeneralAnaya->transfer_2 = nodeTasquena;
    nodeTasquena->transfer_1 = nodeGeneralAnaya;

    // Línea 3
    nodeIndiosVerdes->transfer_1 = nodeDeportivo18DeMarzo;
    nodeDeportivo18DeMarzo->transfer_1 = nodeIndiosVerdes;
    nodeDeportivo18DeMarzo->transfer_2 = nodePotrero;
    nodePotrero->transfer_1 = nodeDeportivo18DeMarzo;
    nodePotrero->transfer_2 = nodeLaRaza;
    nodeLaRaza->transfer_1 = nodePotrero;
    nodeLaRaza->transfer_2 = nodeTlatelolco;
    nodeTlatelolco->transfer_1 = nodeLaRaza;
    nodeTlatelolco->transfer_2 = nodeGuerrero;
    nodeGuerrero->transfer_1 = nodeTlatelolco;
    nodeGuerrero->transfer_2 = nodeHidalgo2;
    nodeHidalgo2->transfer_1 = nodeGuerrero;
    nodeHidalgo2->transfer_2 = nodeJuarez;
    nodeJuarez->transfer_1 = nodeHidalgo2;
    nodeJuarez->transfer_2 = nodeBalderas2;
    nodeBalderas2->transfer_1 = nodeJuarez;
    nodeBalderas2->transfer_2 = nodeNiñosHeroes;
    nodeNiñosHeroes->transfer_1 = nodeBalderas2;
    nodeNiñosHeroes->transfer_2 = nodeHospitalGeneral;
    nodeHospitalGeneral->transfer_1 = nodeNiñosHeroes;
    nodeHospitalGeneral->transfer_2 = nodeCentroMedico2;
    nodeCentroMedico2->transfer_1 = nodeHospitalGeneral;
    nodeCentroMedico2->transfer_2 = nodeEtiopia;
    nodeEtiopia->transfer_1 = nodeCentroMedico2;
    nodeEtiopia->transfer_2 = nodeEugenia;
    nodeEugenia->transfer_1 = nodeEtiopia;
    nodeEugenia->transfer_2 = nodeDivisionDelNorte;
    nodeDivisionDelNorte->transfer_1 = nodeEugenia;
    nodeDivisionDelNorte->transfer_2 = nodeZapata2;
    nodeZapata2->transfer_1 = nodeDivisionDelNorte;
    nodeZapata2->transfer_2 = nodeCoyoacan;
    nodeCoyoacan->transfer_1 = nodeZapata2;
    nodeCoyoacan->transfer_2 = nodeViveros;

    // Línea 7
    nodeElRosario->transfer_1 = nodeAquilesSerdan;
    nodeAquilesSerdan->transfer_1 = nodeElRosario;
    nodeAquilesSerdan->transfer_2 = nodeCamarones;
    nodeCamarones->transfer_1 = nodeAquilesSerdan;
    nodeCamarones->transfer_2 = nodeRefineria;
    nodeRefineria->transfer_1 = nodeCamarones;
    nodeRefineria->transfer_2 = nodeTacuba2;
    nodeTacuba2->transfer_1 = nodeRefineria;
    nodeTacuba2->transfer_2 = nodeSanJoaquin;
    nodeSanJoaquin->transfer_1 = nodeTacuba2;
    nodeSanJoaquin->transfer_2 = nodePolanco;
    nodePolanco->transfer_1 = nodeSanJoaquin;
    nodePolanco->transfer_2 = nodeAuditorio;
    nodeAuditorio->transfer_1 = nodePolanco;
    nodeAuditorio->transfer_2 = nodeConstituyentes;
    nodeConstituyentes->transfer_1 = nodeAuditorio;
    nodeConstituyentes->transfer_2 = nodeTacubaya3;
    nodeTacubaya3->transfer_1 = nodeConstituyentes;
    nodeTacubaya3->transfer_2 = nodeSanPedroDeLosPinos;
    nodeSanPedroDeLosPinos->transfer_1 = nodeTacubaya3;
    nodeSanPedroDeLosPinos->transfer_2 = nodeSanAntonio;
    nodeSanAntonio->transfer_1 = nodeSanPedroDeLosPinos;
    nodeSanAntonio->transfer_2 = nodeMixcoac2;
    nodeMixcoac2->transfer_1 = nodeSanAntonio;
    nodeMixcoac2->transfer_2 = nodeBarrancaDelMuerto;

    // Línea 6
    nodeElRosario2->transfer_1 = nodeTezozomoc;
    nodeTezozomoc->transfer_1 = nodeElRosario2;
    nodeTezozomoc->transfer_2 = nodeAzcapotzalco;
    nodeAzcapotzalco->transfer_1 = nodeTezozomoc;
    nodeAzcapotzalco->transfer_2 = nodeFerreria;
    nodeFerreria->transfer_1 = nodeAzcapotzalco;
    nodeFerreria->transfer_2 = nodeNorte45;
    nodeNorte45->transfer_1 = nodeFerreria;
    nodeNorte45->transfer_2 = nodeVallejo2;
    nodeVallejo2->transfer_1 = nodeNorte45;
    nodeVallejo2->transfer_2 = nodeInstitutoDelPetroleo;
    nodeInstitutoDelPetroleo->transfer_1 = nodeVallejo2;
    nodeInstitutoDelPetroleo->transfer_2 = nodeLindavista;
    nodeLindavista->transfer_1 = nodeInstitutoDelPetroleo;
    nodeDeportivo4Caminos->transfer_1 = nodeLindavista;
    nodeDeportivo4Caminos->transfer_2 = nodeLaVillaBasílica;
    nodeLaVillaBasílica->transfer_1 = nodeDeportivo4Caminos;

    // Línea 4
    nodeMartínCarrera->transfer_1 = nodeTalisman;
    nodeTalisman->transfer_1 = nodeMartínCarrera;
    nodeTalisman->transfer_2 = nodeBondojito;
    nodeBondojito->transfer_1 = nodeTalisman;
    nodeBondojito->transfer_2 = nodeConsulado2;
    nodeConsulado2->transfer_1 = nodeBondojito;
    nodeConsulado2->transfer_2 = nodeCanalDelNorte;
    nodeCanalDelNorte->transfer_1 = nodeConsulado2;
    nodeCanalDelNorte->transfer_2 = nodeMorelos;
    nodeMorelos->transfer_1 = nodeCanalDelNorte;
    nodeMorelos->transfer_2 = nodeCandelaria2;
    nodeCandelaria2->transfer_1 = nodeMorelos;
    nodeCandelaria2->transfer_2 = nodeFrayServando;
    nodeFrayServando->transfer_1 = nodeCandelaria2;
    nodeFrayServando->transfer_2 = nodeJamaica2;
    nodeJamaica2->transfer_1 = nodeFrayServando;
    nodeJamaica2->transfer_2 = nodeSantaAnita;
    nodeSantaAnita->transfer_1 = nodeJamaica2;

    // Estación B
    nodeChapultepec->transfer_1 = nodeB;
    nodeChapultepec->transfer_2 = nodeSevilla;
    nodeSevilla->transfer_1 = nodeChapultepec;
    nodeSevilla->transfer_2 = nodeInsurgentes;
    nodeInsurgentes->transfer_1 = nodeSevilla;
    nodeInsurgentes->transfer_2 = nodeCuauhtemoc;
    nodeCuauhtemoc->transfer_1 = nodeInsurgentes;
    nodeCuauhtemoc->transfer_2 = nodeBalderas;
    nodeBalderas->transfer_1 = nodeCuauhtemoc;
    nodeBalderas->transfer_2 = nodeSaltoDelAgua;
    nodeSaltoDelAgua->transfer_1 = nodeBalderas;
    nodeSaltoDelAgua->transfer_2 = nodeIsabelLaCatolica;
    nodeIsabelLaCatolica->transfer_1 = nodeSaltoDelAgua;
    nodeIsabelLaCatolica->transfer_2 = nodePinoSuarez;

    string start_station = "A";
    string end_station = "I";

    vector<string> shortest_path = dijkstra_shortest_path(graph, start_station, end_station);

    cout << "Shortest path from " << start_station << " to " << end_station << ":" << endl;
    for (int i = 0; i < shortest_path.size() - 1; i++)
    {
        cout << shortest_path[i] << " (" << graph[i]->line << ") -> ";
    }
    cout << shortest_path.back() << endl;

    return 0;
}
