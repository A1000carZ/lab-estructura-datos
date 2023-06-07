#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <unordered_map>

using namespace std;

struct Node
{
    string name;
    string line;
    vector<Node *> neighbors;

    Node(string name, string line) : name(name), line(line) {}
};

typedef pair<int, Node *> pin;

vector<string> dijkstra_shortest_path(vector<Node *> graph, string start, string end, bool half_travel)
{
    unordered_map<string, int> distances;
    unordered_map<string, string> previous;
    priority_queue<pin, vector<pin>, greater<pin> > pq;

    for (Node *node : graph)
    {
        distances[node->name] = numeric_limits<int>::max();
        previous[node->name] = "";
    }

    distances[start] = 0;
    for (Node *node : graph)
    {
        if (node->name == start)
        {
            pq.push(make_pair(0, node));
            break;
        }
    }

    while (!pq.empty())
    {
        int current_distance = pq.top().first;
        Node *current_node = pq.top().second;
        pq.pop();

        if (current_node->name == end)
        {
            break;
        }

        if (current_distance > distances[current_node->name])
        {
            continue;
        }

        for (Node *neighbor : current_node->neighbors)
        {
            int weight = 1;
            if (half_travel && neighbor->line != current_node->line)
            {
                weight = 3;
            }
            int distance = current_distance + weight;
            if (distance < distances[neighbor->name])
            {
                distances[neighbor->name] = distance;
                previous[neighbor->name] = current_node->name;
                pq.push(make_pair(distance, neighbor));
            }
        }
    }

    vector<string> path;
    string current = end;
    while (current != "")
    {
        path.insert(path.begin(), current);
        current = previous[current];
    }

    return path;
}
vector<string> get_route_instructions(const vector<string>& route, const vector<Node*>& graph)
{
    vector<string> instructions;

    if (route.size() <= 1)
    {
        instructions.push_back("Ruta inválida");
        return instructions;
    }

    for (size_t i = 0; i < route.size() - 1; ++i)
    {
        string current_station = route[i];
        string next_station = route[i + 1];

        Node* current_node = NULL;
        Node* next_node = NULL;

        // Buscar los nodos correspondientes a las estaciones actual y siguiente en el grafo
        for (Node* node : graph)
        {
            if (node->name == current_station)
                current_node = node;
            if (node->name == next_station)
                next_node = node;
        }

        if (current_node && next_node)
        {
            if (current_node->line != next_node->line)
            {
                instructions.push_back("Transborda en " + current_station + " para llegar a " + next_station + ".");
            }
            else
            {
                instructions.push_back("Toma " + current_station + " y luego sigue hacia " + next_station + ".");
            }
        }
        else
        {
            instructions.push_back("No se encontró información completa de las estaciones.");
        }
    }

    instructions.push_back("Has llegado a tu destino.");

    return instructions;
}

int main()
{
    vector<Node *> graph;
    // Línea 1
    Node *observatorio = new Node("Observatorio", "Línea 1");
    Node *tacubayaLinea1 = new Node("Tacubaya Linea 1", "Línea 1");
    Node *juanacatlan = new Node("Juanacatlan", "Línea 1");
    Node *chapultepec = new Node("Chapultepec", "Línea 1");
    Node *sevilla = new Node("Sevilla", "Línea 1");
    Node *insurgentes = new Node("Insurgentes", "Línea 1");
    Node *cuauhtemoc = new Node("Cuauhtemoc", "Línea 1");
    Node *balderas = new Node("Balderas Linea 1", "Línea 1");
    Node *saltoDelAgua = new Node("Salto del Agua Linea 1", "Línea 1");
    Node *isabelLaCatolica = new Node("Isabel la Catolica", "Línea 1");
    Node *pinoSuarez = new Node("Pino Suarez Linea 1", "Línea 1");
    Node *merced = new Node("Merced", "Línea 1");
    Node *candelaria = new Node("Candelaria Linea 1", "Línea 1");
    Node *sanLazaro = new Node("San Lazaro", "Línea 1");
    Node *moctezuma = new Node("Moctezuma", "Línea 1");
    Node *balbuena = new Node("Balbuena", "Línea 1");
    Node *boulevardPuertoAereo = new Node("Boulevard Puerto Aéreo", "Línea 1");
    Node *gomezFarias = new Node("Gómez Farías", "Línea 1");
    Node *zaragoza = new Node("Zaragoza", "Línea 1");
    Node *pantitlanLinea1 = new Node("Pantitlan Linea 1", "Línea 1");
    // Línea 5
    Node *nodePantitlanLinea5 = new Node("Pantitlan Linea 5", "Linea 5");
    Node *nodeHangares = new Node("Hangares", "Linea 5");
    Node *nodeTerminalAerea = new Node("Terminal Aerea", "Linea 5");
    Node *nodeOceaniaLinea5 = new Node("Oceania Linea 5", "Linea 5");
    Node *nodeAragon = new Node("Aragon", "Linea 5");
    Node *nodeEduardoMolina = new Node("Eduardo Molina", "Linea 5");
    Node *nodeConsuladoLinea5 = new Node("Consulado Linea 5", "Linea 5");
    Node *nodeValleGomez = new Node("Valle Gomez", "Linea 5");
    Node *nodeMisterios = new Node("Misterios", "Linea 5");
    Node *nodeLaRazaLinea5 = new Node("La Raza Linea 5", "Linea 5");
    Node *nodeAutobusesdelNorte = new Node("Autobuses del Norte", "Linea 5");
    Node *nodeInstitutodelPetroleoLinea5 = new Node("Instituto del Petroleo Linea 5", "Linea 5");
    Node *nodePolitecnico = new Node("Politecnico", "Linea 5");
    // Línea 9
    Node *nodeTacubayaLinea9 = new Node("Tacubaya Linea 9", "Linea 9");
    Node *nodePatriotismo = new Node("Patriotismo", "Linea 9");
    Node *nodeChilpancingo = new Node("Chilpancingo", "Linea 9");
    Node *nodeCentroMedicoLinea9 = new Node("Centro Medico Linea 9", "Linea 9");
    Node *nodeLazaroCardenas = new Node("Lazaro Cardenas", "Linea 9");
    Node *nodeChabacanoLinea9 = new Node("Chabacano Linea 9", "Linea 9");
    Node *nodeJamaicaLinea9 = new Node("Jamaica", "Linea 9");
    Node *nodeMixiuhca = new Node("Mixiuhca", "Linea 9");
    Node *nodeVelodromo = new Node("Velodromo", "Linea 9");
    Node *nodeCiudadDeportiva = new Node("Ciudad Deportiva", "Linea 9");
    Node *nodePuebla = new Node("Puebla", "Linea 9");
    Node *nodePantitlanLinea9 = new Node("Pantitlan Linea 9", "Linea 9");
    // Línea 8
    Node *nodeGaribaldi = new Node("Garibaldi", "Linea 8");
    Node *nodeBellasArtes = new Node("Bellas Artes", "Linea 8");
    Node *nodeSanJuanDeLetran = new Node("San Juan De Letran", "Linea 8");
    Node *nodeSaltoDelAguaLinea8 = new Node("Salto del Agua Linea 8", "Linea 8");
    Node *nodeDoctores = new Node("Doctores", "Linea 8");
    Node *nodeObrera = new Node("Obrera", "Linea 8");
    Node *nodeChabacanoLinea8 = new Node("Chabacano Linea 8", "Linea 8");
    Node *nodeLaViga = new Node("La Viga", "Linea 8");
    Node *nodeSantaAnitaLinea8 = new Node("Santa Anita Linea 8", "Linea 8");
    Node *nodeCoyuya = new Node("Coyuya", "Linea 8");
    Node *nodeIztacalco = new Node("Iztacalco", "Linea 8");
    Node *nodeApatlaco = new Node("Apatlaco", "Linea 8");
    Node *nodeAculco = new Node("Aculco", "Linea 8");
    Node *nodeEscuadron201 = new Node("Escuadron 201", "Linea 8");
    Node *nodeAtlalilcoLinea8 = new Node("Atlalilco Linea 8", "Linea 8");
    Node *nodeIztapalapa = new Node("Iztapalapa", "Linea 8");
    Node *nodeCerrodelaEstrella = new Node("Cerro de la Estrella", "Linea 8");
    Node *nodeUAMIztapalapa = new Node("UAM Iztapalapa", "Linea 8");
    Node *nodeConstitucionde1917 = new Node("Constitucion de 1917", "Linea 8");
    // Línea 12
    Node *nodeMixcoacLinea12 = new Node("Mixcoac Linea 12", "Linea 12");
    Node *nodeInsurgentesSur = new Node("Insurgentes Sur", "Linea 12");
    Node *nodeHospital20DeNoviembre = new Node("Hospital 20 de Noviembre", "Linea 12");
    Node *nodeZapata = new Node("Zapata", "Linea 12");
    Node *nodeParqueDeLosVenados = new Node("Parque de Los Venados", "Linea 12");
    Node *nodeEjeCentral = new Node("Eje Central", "Linea 12");
    Node *nodeErmitaLinea12 = new Node("Ermita", "Linea 12");
    Node *nodeMexicaltzingo = new Node("Mexicaltzingo", "Linea 12");
    Node *nodeAtlalilcoLinea12 = new Node("Atlalilco Linea 12", "Linea 12");
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
    Node *nodeTacubaLinea2 = new Node("Tacuba Linea 2", "Linea 2");
    Node *nodeCuitlahuac = new Node("Cuitlahuac", "Linea 2");
    Node *nodePopotla = new Node("Popotla", "Linea 2");
    Node *nodeColegioMilitar = new Node("Colegio Militar", "Linea 2");
    Node *nodeNormal = new Node("Normal", "Linea 2");
    Node *nodeSanCosme = new Node("San Cosme", "Linea 2");
    Node *nodeRevolucion = new Node("Revolucion", "Linea 2");
    Node *nodeHidalgoLinea2 = new Node("Hidalgo Linea 2", "Linea 2");
    Node *nodeBellasArtesLinea2 = new Node("Bellas Artes Linea 2", "Linea 2");
    Node *nodeAllende = new Node("Allende", "Linea 2");
    Node *nodeZocalo = new Node("Zocalo", "Linea 2");
    Node *nodePinoSuarezLinea2 = new Node("Pino Suarez Linea 2", "Linea 2");
    Node *nodeSanAntonioAbad = new Node("San Antonio Abad", "Linea 2");
    Node *nodeChabacanoLinea2 = new Node("Chabacano Linea 2", "Linea 2");
    Node *nodeViaducto = new Node("Viaducto", "Linea 2");
    Node *nodeXola = new Node("Xola", "Linea 2");
    Node *nodeVillaDeCortes = new Node("Villa de Cortes", "Linea 2");
    Node *nodeNativitas = new Node("Nativitas", "Linea 2");
    Node *nodePortales = new Node("Portales", "Linea 2");
    Node *nodeErmita = new Node("Ermita Linea 12", "Linea 2");
    Node *nodeGeneralAnaya = new Node("General Anaya", "Linea 2");
    Node *nodeTasquena = new Node("Tasquena", "Linea 2");
    // Línea 3
    Node *nodeIndiosVerdes = new Node("Indios Verdes", "Linea 3");
    Node *nodeDeportivo18DeMarzo = new Node("Deportivo 18 de Marzo Linea 3", "Linea 3");
    Node *nodePotrero = new Node("Potrero", "Linea 3");
    Node *nodeLaRazaLinea3 = new Node("La Raza Linea 3", "Linea 3");
    Node *nodeTlatelolco = new Node("Tlatelolco", "Linea 3");
    Node *nodeGuerreroLinea3 = new Node("Guerrero Linea 3", "Linea 3");
    Node *nodeHidalgoLinea3 = new Node("Hidalgo Linea 3", "Linea 3");
    Node *nodeJuarez = new Node("Juarez", "Linea 3");
    Node *nodeBalderasLinea3 = new Node("Balderas Linea 3", "Linea 3");
    Node *nodeNinosHeroes = new Node("Ninos Heroes", "Linea 3");
    Node *nodeHospitalGeneral = new Node("Hospital General", "Linea 3");
    Node *nodeCentroMedicoLinea3 = new Node("Centro Medico Linea 3", "Linea 3");
    Node *nodeEtiopia = new Node("Etiopia", "Linea 3");
    Node *nodeEugenia = new Node("Eugenia", "Linea 3");
    Node *nodeDivisionDelNorte = new Node("Division del Norte", "Linea 3");
    Node *nodeZapataLinea3 = new Node("Zapata Linea 3", "Linea 3");
    Node *nodeCoyoacan = new Node("Coyoacan", "Linea 3");
    Node *nodeViveros = new Node("Viveros", "Linea 3");
    Node *nodeMiguelAngeldeQuevedo = new Node("Miguel Angel de Quevedo", "Linea 3");
    Node *nodeCopilco = new Node("Copilco", "Linea 3");
    Node *nodeUniversidad = new Node("Universidad", "Linea 3");
    // Línea 7
    Node *nodeElRosarioLinea7 = new Node("El Rosario Linea 7", "Linea 7");
    Node *nodeAquilesSerdan = new Node("Aquiles Serdan", "Linea 7");
    Node *nodeCamarones = new Node("Camarones", "Linea 7");
    Node *nodeRefineria = new Node("Refineria", "Linea 7");
    Node *nodeTacubaLinea7 = new Node("Tacuba Linea 7", "Linea 7");
    Node *nodeSanJoaquin = new Node("San Joaquin", "Linea 7");
    Node *nodePolanco = new Node("Polanco", "Linea 7");
    Node *nodeAuditorio = new Node("Auditorio", "Linea 7");
    Node *nodeConstituyentes = new Node("Constituyentes", "Linea 7");
    Node *nodeTacubayaLinea7 = new Node("Tacubaya Linea 7", "Linea 7");
    Node *nodeSanPedrodelosPinos = new Node("San Pedro de los Pinos", "Linea 7");
    Node *nodeSanAntonio = new Node("San Antonio", "Linea 7");
    Node *nodeMixcoacLinea7 = new Node("Mixcoac Linea 7", "Linea 7");
    Node *nodeBarrancadelMuerto = new Node("Barranca del Muerto", "Linea 7");
    // Línea 6
    Node *nodeElRosarioLinea6 = new Node("El Rosario Linea 6", "Linea 6");
    Node *nodeTezozomoc = new Node("Tezozomoc", "Linea 6");
    Node *nodeAzcapotzalco = new Node("Azcapotzalco", "Linea 6");
    Node *nodeFerreria = new Node("Ferreria", "Linea 6");
    Node *nodeNorte45 = new Node("Norte 45", "Linea 6");
    Node *nodeVallejo = new Node("Vallejo", "Linea 6");
    Node *nodeInstitutoDelPetroleoLinea6 = new Node("Instituto del Petroleo Linea 6", "Linea 6");
    Node *nodeLindavista = new Node("Lindavista", "Linea 6");
    Node *nodeDeportivo18DeMarzoLinea6 = new Node("Deportivo 18 de Marzo Linea 6", "Linea 6");
    Node *nodeLaVillaBasílica = new Node("La Villa Basilica", "Linea 6");
    Node *nodeMartinCarreraLinea6 = new Node("Martin Carrera Linea 6", "Linea 6");
    // Línea 4
    Node *nodeMartínCarreraLinea4 = new Node("Martin Carrera Linea 4", "Linea 4");
    Node *nodeTalisman = new Node("Talisman", "Linea 4");
    Node *nodeBondojito = new Node("Bondojito", "Linea 4");
    Node *nodeConsuladoLinea4 = new Node("Consulado Linea 4", "Linea 4");
    Node *nodeCanalDelNorte = new Node("Canal del Norte", "Linea 4");
    Node *nodeMorelosLinea4 = new Node("Morelos Linea 4", "Linea 4");
    Node *nodeCandelariaLinea4 = new Node("Candelaria", "Linea 4");
    Node *nodeFrayServando = new Node("Fray Servando", "Linea 4");
    Node *nodeJamaicaLinea4 = new Node("Jamaica Linea 4", "Linea 4");
    Node *nodeSantaAnita = new Node("Santa Anita Linea 4", "Linea 4");
    // Línea B
    Node *nodeBuenavista = new Node("Buenavista", "Linea B");
    Node *nodeGuerreroLineaB = new Node("Guerrero", "Linea B");
    Node *nodeGaribaldiLineaB = new Node("Garibaldi Linea B", "Linea B");
    Node *nodeLagunilla = new Node("Lagunilla", "Linea B");
    Node *nodeTepito = new Node("Tepito", "Linea B");
    Node *nodeMorelosLineaB = new Node("Morelos", "Linea B");
    Node *nodeSanLazaroLineaB = new Node("San Lazaro", "Linea B");
    Node *nodeRicardoFloresMagon = new Node("Ricardo Flores Magon", "Linea B");
    Node *nodeRomeroRubio = new Node("Romero Rubio", "Linea B");
    Node *nodeOceaniaLineaB = new Node("Oceania Linea B", "Linea B");
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

    // Línea 1
    observatorio->neighbors.push_back(tacubayaLinea1);
    tacubayaLinea1->neighbors.push_back(observatorio);
    tacubayaLinea1->neighbors.push_back(juanacatlan);
    tacubayaLinea1->neighbors.push_back(nodeTacubayaLinea9);
    tacubayaLinea1->neighbors.push_back(nodeTacubayaLinea7);
    juanacatlan->neighbors.push_back(tacubayaLinea1);
    juanacatlan->neighbors.push_back(chapultepec);
    chapultepec->neighbors.push_back(juanacatlan);
    chapultepec->neighbors.push_back(sevilla);
    sevilla->neighbors.push_back(chapultepec);
    sevilla->neighbors.push_back(insurgentes);
    insurgentes->neighbors.push_back(sevilla);
    insurgentes->neighbors.push_back(cuauhtemoc);
    cuauhtemoc->neighbors.push_back(insurgentes);
    cuauhtemoc->neighbors.push_back(balderas);
    balderas->neighbors.push_back(cuauhtemoc);
    balderas->neighbors.push_back(saltoDelAgua);
    saltoDelAgua->neighbors.push_back(balderas);
    saltoDelAgua->neighbors.push_back(isabelLaCatolica);
    saltoDelAgua->neighbors.push_back(nodeSaltoDelAguaLinea8);
    isabelLaCatolica->neighbors.push_back(saltoDelAgua);
    isabelLaCatolica->neighbors.push_back(pinoSuarez);
    pinoSuarez->neighbors.push_back(isabelLaCatolica);
    pinoSuarez->neighbors.push_back(merced);
    pinoSuarez->neighbors.push_back(nodePinoSuarezLinea2);
    merced->neighbors.push_back(pinoSuarez);
    merced->neighbors.push_back(candelaria);
    candelaria->neighbors.push_back(merced);
    candelaria->neighbors.push_back(sanLazaro);
    candelaria->neighbors.push_back(nodeCandelariaLinea4);
    sanLazaro->neighbors.push_back(candelaria);
    sanLazaro->neighbors.push_back(moctezuma);
    moctezuma->neighbors.push_back(sanLazaro);
    moctezuma->neighbors.push_back(balbuena);
    balbuena->neighbors.push_back(moctezuma);
    balbuena->neighbors.push_back(boulevardPuertoAereo);
    boulevardPuertoAereo->neighbors.push_back(balbuena);
    boulevardPuertoAereo->neighbors.push_back(gomezFarias);
    gomezFarias->neighbors.push_back(boulevardPuertoAereo);
    gomezFarias->neighbors.push_back(zaragoza);
    zaragoza->neighbors.push_back(gomezFarias);
    zaragoza->neighbors.push_back(pantitlanLinea1);
    pantitlanLinea1->neighbors.push_back(zaragoza);
    pantitlanLinea1->neighbors.push_back(nodePantitlanLinea5);
    pantitlanLinea1->neighbors.push_back(nodePantitlanLinea9);
    // linea 5
    nodePantitlanLinea5->neighbors.push_back(pantitlanLinea1);
    nodePantitlanLinea5->neighbors.push_back(nodePantitlanLinea9);
    nodePantitlanLinea5->neighbors.push_back(nodeHangares);
    nodeHangares->neighbors.push_back(nodePantitlanLinea5);
    nodeHangares->neighbors.push_back(nodeTerminalAerea);
    nodeTerminalAerea->neighbors.push_back(nodeHangares);
    nodeTerminalAerea->neighbors.push_back(nodeOceaniaLinea5);
    nodeOceaniaLinea5->neighbors.push_back(nodeAragon);
    nodeOceaniaLinea5->neighbors.push_back(nodeOceaniaLineaB);
    nodeOceaniaLinea5->neighbors.push_back(nodeTerminalAerea);
    nodeAragon->neighbors.push_back(nodeOceaniaLinea5);
    nodeAragon->neighbors.push_back(nodeEduardoMolina);
    nodeEduardoMolina->neighbors.push_back(nodeAragon);
    nodeEduardoMolina->neighbors.push_back(nodeConsuladoLinea5);
    nodeConsuladoLinea5->neighbors.push_back(nodeEduardoMolina);
    nodeConsuladoLinea5->neighbors.push_back(nodeValleGomez);
    nodeConsuladoLinea5->neighbors.push_back(nodeConsuladoLinea4);
    nodeValleGomez->neighbors.push_back(nodeConsuladoLinea5);
    nodeValleGomez->neighbors.push_back(nodeMisterios);
    nodeMisterios->neighbors.push_back(nodeValleGomez);
    nodeMisterios->neighbors.push_back(nodeLaRazaLinea5);
    nodeLaRazaLinea5->neighbors.push_back(nodeMisterios);
    nodeLaRazaLinea5->neighbors.push_back(nodeAutobusesdelNorte);
    nodeLaRazaLinea5->neighbors.push_back(nodeLaRazaLinea3);
    nodeAutobusesdelNorte->neighbors.push_back(nodeLaRazaLinea5);
    nodeAutobusesdelNorte->neighbors.push_back(nodeInstitutodelPetroleoLinea5);
    nodeInstitutodelPetroleoLinea5->neighbors.push_back(nodeAutobusesdelNorte);
    nodeInstitutodelPetroleoLinea5->neighbors.push_back(nodePolitecnico);
    nodeInstitutodelPetroleoLinea5->neighbors.push_back(nodeInstitutoDelPetroleoLinea6);
    nodePolitecnico->neighbors.push_back(nodeInstitutodelPetroleoLinea5);
    // linea 9
    nodePantitlanLinea9->neighbors.push_back(nodePantitlanLinea5);
    nodePantitlanLinea9->neighbors.push_back(pantitlanLinea1);
    nodePantitlanLinea9->neighbors.push_back(nodePuebla);
    nodePuebla->neighbors.push_back(nodePantitlanLinea9);
    nodePuebla->neighbors.push_back(nodeCiudadDeportiva);
    nodeCiudadDeportiva->neighbors.push_back(nodePuebla);
    nodeCiudadDeportiva->neighbors.push_back(nodeVelodromo);
    nodeVelodromo->neighbors.push_back(nodeCiudadDeportiva);
    nodeVelodromo->neighbors.push_back(nodeMixiuhca);
    nodeMixiuhca->neighbors.push_back(nodeVelodromo);
    nodeMixiuhca->neighbors.push_back(nodeJamaicaLinea9);
    nodeJamaicaLinea9->neighbors.push_back(nodeMixiuhca);
    nodeJamaicaLinea9->neighbors.push_back(nodeChabacanoLinea9);
    nodeJamaicaLinea9->neighbors.push_back(nodeJamaicaLinea4);
    nodeChabacanoLinea9->neighbors.push_back(nodeJamaicaLinea9);
    nodeChabacanoLinea9->neighbors.push_back(nodeLazaroCardenas);
    nodeChabacanoLinea9->neighbors.push_back(nodeChabacanoLinea2);
    nodeChabacanoLinea9->neighbors.push_back(nodeChabacanoLinea8);
    nodeLazaroCardenas->neighbors.push_back(nodeChabacanoLinea9);
    nodeLazaroCardenas->neighbors.push_back(nodeCentroMedicoLinea9);
    nodeCentroMedicoLinea9->neighbors.push_back(nodeLazaroCardenas);
    nodeCentroMedicoLinea9->neighbors.push_back(nodeChilpancingo);
    nodeCentroMedicoLinea9->neighbors.push_back(nodeCentroMedicoLinea3);
    nodeChilpancingo->neighbors.push_back(nodeCentroMedicoLinea9);
    nodeChilpancingo->neighbors.push_back(nodePatriotismo);
    nodePatriotismo->neighbors.push_back(nodeChilpancingo);
    nodePatriotismo->neighbors.push_back(nodeTacubayaLinea9);
    nodeTacubayaLinea9->neighbors.push_back(nodePatriotismo);
    nodeTacubayaLinea9->neighbors.push_back(nodeTacubayaLinea7);
    nodeTacubayaLinea9->neighbors.push_back(tacubayaLinea1);
    // linea 8
    nodeGaribaldi->neighbors.push_back(nodeBellasArtes);
    nodeGaribaldi->neighbors.push_back(nodeGaribaldiLineaB);
    nodeBellasArtes->neighbors.push_back(nodeGaribaldi);
    nodeBellasArtes->neighbors.push_back(nodeSanJuanDeLetran);
    nodeBellasArtes->neighbors.push_back(nodeBellasArtesLinea2);
    nodeSanJuanDeLetran->neighbors.push_back(nodeBellasArtes);
    nodeSanJuanDeLetran->neighbors.push_back(nodeSaltoDelAguaLinea8);
    nodeSaltoDelAguaLinea8->neighbors.push_back(nodeSanJuanDeLetran);
    nodeSaltoDelAguaLinea8->neighbors.push_back(nodeDoctores);
    nodeSaltoDelAguaLinea8->neighbors.push_back(saltoDelAgua);
    nodeDoctores->neighbors.push_back(nodeSaltoDelAguaLinea8);
    nodeDoctores->neighbors.push_back(nodeObrera);
    nodeObrera->neighbors.push_back(nodeChabacanoLinea8);
    nodeObrera->neighbors.push_back(nodeDoctores);
    nodeChabacanoLinea8->neighbors.push_back(nodeObrera);
    nodeChabacanoLinea8->neighbors.push_back(nodeLaViga);
    nodeChabacanoLinea8->neighbors.push_back(nodeChabacanoLinea9);
    nodeChabacanoLinea8->neighbors.push_back(nodeChabacanoLinea2);
    nodeLaViga->neighbors.push_back(nodeChabacanoLinea8);
    nodeLaViga->neighbors.push_back(nodeSantaAnitaLinea8);
    nodeSantaAnitaLinea8->neighbors.push_back(nodeLaViga);
    nodeSantaAnitaLinea8->neighbors.push_back(nodeCoyuya);
    nodeSantaAnitaLinea8->neighbors.push_back(nodeSantaAnita);
    nodeCoyuya->neighbors.push_back(nodeSantaAnitaLinea8);
    nodeCoyuya->neighbors.push_back(nodeIztacalco);
    nodeIztacalco->neighbors.push_back(nodeCoyuya);
    nodeIztacalco->neighbors.push_back(nodeApatlaco);
    nodeApatlaco->neighbors.push_back(nodeAculco);
    nodeApatlaco->neighbors.push_back(nodeIztacalco);
    nodeAculco->neighbors.push_back(nodeApatlaco);
    nodeAculco->neighbors.push_back(nodeEscuadron201);
    nodeEscuadron201->neighbors.push_back(nodeAculco);
    nodeEscuadron201->neighbors.push_back(nodeAtlalilcoLinea8);
    nodeAtlalilcoLinea8->neighbors.push_back(nodeEscuadron201);
    nodeAtlalilcoLinea8->neighbors.push_back(nodeIztapalapa);
    nodeAtlalilcoLinea8->neighbors.push_back(nodeAtlalilcoLinea12);
    nodeIztapalapa->neighbors.push_back(nodeAtlalilcoLinea8);
    nodeIztapalapa->neighbors.push_back(nodeCerrodelaEstrella);
    nodeCerrodelaEstrella->neighbors.push_back(nodeUAMIztapalapa);
    nodeCerrodelaEstrella->neighbors.push_back(nodeIztapalapa);
    nodeUAMIztapalapa->neighbors.push_back(nodeCerrodelaEstrella);
    nodeUAMIztapalapa->neighbors.push_back(nodeConstitucionde1917);
    nodeConstitucionde1917->neighbors.push_back(nodeUAMIztapalapa);
    // Linea 12
    nodeAtlalilcoLinea12->neighbors.push_back(nodeMexicaltzingo);
    nodeAtlalilcoLinea12->neighbors.push_back(nodeAtlalilcoLinea8);
    nodeMexicaltzingo->neighbors.push_back(nodeAtlalilcoLinea12);
    nodeMexicaltzingo->neighbors.push_back(nodeErmita);
    nodeErmita->neighbors.push_back(nodeMexicaltzingo);
    nodeErmita->neighbors.push_back(nodeEjeCentral);
    nodeErmita->neighbors.push_back(nodeErmitaLinea12);
    nodeEjeCentral->neighbors.push_back(nodeErmita);
    nodeEjeCentral->neighbors.push_back(nodeParqueDeLosVenados);
    nodeParqueDeLosVenados->neighbors.push_back(nodeEjeCentral);
    nodeParqueDeLosVenados->neighbors.push_back(nodeZapata);
    nodeZapata->neighbors.push_back(nodeParqueDeLosVenados);
    nodeZapata->neighbors.push_back(nodeHospital20DeNoviembre);
    nodeZapata->neighbors.push_back(nodeZapataLinea3);
    nodeHospital20DeNoviembre->neighbors.push_back(nodeZapata);
    nodeHospital20DeNoviembre->neighbors.push_back(nodeInsurgentesSur);
    nodeInsurgentesSur->neighbors.push_back(nodeHospital20DeNoviembre);
    nodeInsurgentesSur->neighbors.push_back(nodeMixcoacLinea12);
    nodeMixcoacLinea12->neighbors.push_back(nodeInsurgentesSur);
    nodeMixcoacLinea12->neighbors.push_back(nodeMixcoacLinea7);
    // linea 2
    nodeCuatroCaminos->neighbors.push_back(nodePanteones);
    nodePanteones->neighbors.push_back(nodeCuatroCaminos);
    nodePanteones->neighbors.push_back(nodeTacubaLinea2);
    nodeTacubaLinea2->neighbors.push_back(nodePanteones);
    nodeTacubaLinea2->neighbors.push_back(nodeCuitlahuac);
    nodeTacubaLinea2->neighbors.push_back(nodeTacubaLinea7);
    nodeCuitlahuac->neighbors.push_back(nodeTacubaLinea2);
    nodeCuitlahuac->neighbors.push_back(nodePopotla);
    nodePopotla->neighbors.push_back(nodeCuitlahuac);
    nodePopotla->neighbors.push_back(nodeColegioMilitar);
    nodeColegioMilitar->neighbors.push_back(nodePopotla);
    nodeColegioMilitar->neighbors.push_back(nodeNormal);
    nodeNormal->neighbors.push_back(nodeColegioMilitar);
    nodeNormal->neighbors.push_back(nodeSanCosme);
    nodeSanCosme->neighbors.push_back(nodeNormal);
    nodeSanCosme->neighbors.push_back(nodeRevolucion);
    nodeRevolucion->neighbors.push_back(nodeSanCosme);
    nodeRevolucion->neighbors.push_back(nodeHidalgoLinea2);
    nodeHidalgoLinea2->neighbors.push_back(nodeRevolucion);
    nodeHidalgoLinea2->neighbors.push_back(nodeBellasArtesLinea2);
    nodeHidalgoLinea2->neighbors.push_back(nodeHidalgoLinea3);
    nodeBellasArtesLinea2->neighbors.push_back(nodeHidalgoLinea2);
    nodeBellasArtesLinea2->neighbors.push_back(nodeAllende);
    nodeAllende->neighbors.push_back(nodeBellasArtesLinea2);
    nodeAllende->neighbors.push_back(nodeZocalo);
    nodeZocalo->neighbors.push_back(nodeAllende);
    nodeZocalo->neighbors.push_back(nodePinoSuarezLinea2);
    nodePinoSuarezLinea2->neighbors.push_back(nodeZocalo);
    nodePinoSuarezLinea2->neighbors.push_back(nodeSanAntonioAbad);
    nodePinoSuarezLinea2->neighbors.push_back(pinoSuarez);
    nodeSanAntonioAbad->neighbors.push_back(nodePinoSuarezLinea2);
    nodeSanAntonioAbad->neighbors.push_back(nodeChabacanoLinea2);
    nodeChabacanoLinea2->neighbors.push_back(nodeSanAntonioAbad);
    nodeChabacanoLinea2->neighbors.push_back(nodeViaducto);
    nodeChabacanoLinea2->neighbors.push_back(nodeChabacanoLinea8);
    nodeChabacanoLinea2->neighbors.push_back(nodeChabacanoLinea2);
    nodeViaducto->neighbors.push_back(nodeChabacanoLinea2);
    nodeViaducto->neighbors.push_back(nodeXola);
    nodeXola->neighbors.push_back(nodeViaducto);
    nodeXola->neighbors.push_back(nodeVillaDeCortes);
    nodeVillaDeCortes->neighbors.push_back(nodeXola);
    nodeVillaDeCortes->neighbors.push_back(nodeNativitas);
    nodeNativitas->neighbors.push_back(nodeVillaDeCortes);
    nodeNativitas->neighbors.push_back(nodePortales);
    nodePortales->neighbors.push_back(nodeNativitas);
    nodePortales->neighbors.push_back(nodeErmitaLinea12);
    nodeErmitaLinea12->neighbors.push_back(nodePortales);
    nodeErmitaLinea12->neighbors.push_back(nodeGeneralAnaya);
    nodeErmitaLinea12->neighbors.push_back(nodeErmita);
    nodeGeneralAnaya->neighbors.push_back(nodeErmitaLinea12);
    nodeGeneralAnaya->neighbors.push_back(nodeTasquena);
    nodeTasquena->neighbors.push_back(nodeGeneralAnaya);
    //Linea 3
    nodeIndiosVerdes->neighbors.push_back(nodeDeportivo18DeMarzo);
    nodeDeportivo18DeMarzo->neighbors.push_back(nodeIndiosVerdes);
    nodeDeportivo18DeMarzo->neighbors.push_back(nodePotrero);
    nodeDeportivo18DeMarzo->neighbors.push_back(nodeDeportivo18DeMarzoLinea6);
    nodePotrero->neighbors.push_back(nodeDeportivo18DeMarzo);
    nodePotrero->neighbors.push_back(nodeLaRazaLinea3);
    nodeLaRazaLinea3->neighbors.push_back(nodePotrero);
    nodeLaRazaLinea3->neighbors.push_back(nodeTlatelolco);
    nodeLaRazaLinea3->neighbors.push_back(nodeLaRazaLinea5);
    nodeTlatelolco->neighbors.push_back(nodeLaRazaLinea3);
    nodeTlatelolco->neighbors.push_back(nodeGuerreroLinea3);
    nodeGuerreroLinea3->neighbors.push_back(nodeTlatelolco);
    nodeGuerreroLinea3->neighbors.push_back(nodeHidalgoLinea3);
    nodeGuerreroLinea3->neighbors.push_back(nodeGuerreroLineaB);
    nodeHidalgoLinea3->neighbors.push_back(nodeGuerreroLinea3);
    nodeHidalgoLinea3->neighbors.push_back(nodeJuarez);
    nodeHidalgoLinea3->neighbors.push_back(nodeHidalgoLinea2);
    nodeJuarez->neighbors.push_back(nodeHidalgoLinea3);
    nodeJuarez->neighbors.push_back(nodeBalderasLinea3);
    nodeBalderasLinea3->neighbors.push_back(nodeJuarez);
    nodeBalderasLinea3->neighbors.push_back(nodeNinosHeroes);
    nodeBalderasLinea3->neighbors.push_back(balderas);
    nodeNinosHeroes->neighbors.push_back(nodeBalderasLinea3);
    nodeNinosHeroes->neighbors.push_back(nodeHospitalGeneral);
    nodeHospitalGeneral->neighbors.push_back(nodeNinosHeroes);
    nodeHospitalGeneral->neighbors.push_back(nodeCentroMedicoLinea3);
    nodeCentroMedicoLinea3->neighbors.push_back(nodeHospitalGeneral);
    nodeCentroMedicoLinea3->neighbors.push_back(nodeEtiopia);
    nodeCentroMedicoLinea3->neighbors.push_back(nodeCentroMedicoLinea9);
    nodeEtiopia->neighbors.push_back(nodeCentroMedicoLinea3);
    nodeEtiopia->neighbors.push_back(nodeEugenia);
    nodeEugenia->neighbors.push_back(nodeEtiopia);
    nodeEugenia->neighbors.push_back(nodeDivisionDelNorte);
    nodeDivisionDelNorte->neighbors.push_back(nodeEugenia);
    nodeDivisionDelNorte->neighbors.push_back(nodeZapataLinea3);
    nodeZapataLinea3->neighbors.push_back(nodeDivisionDelNorte);
    nodeZapataLinea3->neighbors.push_back(nodeCoyoacan);
    nodeZapataLinea3->neighbors.push_back(nodeZapata);
    nodeCoyoacan->neighbors.push_back(nodeZapataLinea3);
    nodeCoyoacan->neighbors.push_back(nodeViveros);
    nodeViveros->neighbors.push_back(nodeCoyoacan);
    nodeViveros->neighbors.push_back(nodeMiguelAngeldeQuevedo);
    nodeMiguelAngeldeQuevedo->neighbors.push_back(nodeViveros);
    nodeMiguelAngeldeQuevedo->neighbors.push_back(nodeCopilco);
    nodeCopilco->neighbors.push_back(nodeMiguelAngeldeQuevedo);
    nodeCopilco->neighbors.push_back(nodeUniversidad);
    nodeUniversidad->neighbors.push_back(nodeCopilco);
    // linea 7
    nodeElRosarioLinea7->neighbors.push_back(nodeAquilesSerdan);
    nodeElRosarioLinea7->neighbors.push_back(nodeElRosarioLinea6);
    nodeAquilesSerdan->neighbors.push_back(nodeElRosarioLinea7);
    nodeAquilesSerdan->neighbors.push_back(nodeCamarones);
    nodeCamarones->neighbors.push_back(nodeAquilesSerdan);
    nodeCamarones->neighbors.push_back(nodeRefineria);
    nodeRefineria->neighbors.push_back(nodeCamarones);
    nodeRefineria->neighbors.push_back(nodeTacubaLinea7);
    nodeTacubaLinea7->neighbors.push_back(nodeRefineria);
    nodeTacubaLinea7->neighbors.push_back(nodeSanJoaquin);
    nodeTacubaLinea7->neighbors.push_back(nodeTacubaLinea2);
    nodeSanJoaquin->neighbors.push_back(nodeTacubaLinea7);
    nodeSanJoaquin->neighbors.push_back(nodePolanco);
    nodePolanco->neighbors.push_back(nodeSanJoaquin);
    nodePolanco->neighbors.push_back(nodeAuditorio);
    nodeAuditorio->neighbors.push_back(nodePolanco);
    nodeAuditorio->neighbors.push_back(nodeConstituyentes);
    nodeConstituyentes->neighbors.push_back(nodeAuditorio);
    nodeConstituyentes->neighbors.push_back(nodeTacubayaLinea7);
    nodeTacubayaLinea7->neighbors.push_back(nodeConstituyentes);
    nodeTacubayaLinea7->neighbors.push_back(nodeSanPedrodelosPinos);
    nodeTacubayaLinea7->neighbors.push_back(nodeTacubayaLinea9);
    nodeTacubayaLinea7->neighbors.push_back(tacubayaLinea1);
    nodeSanPedrodelosPinos->neighbors.push_back(nodeTacubayaLinea7);
    nodeSanPedrodelosPinos->neighbors.push_back(nodeSanAntonio);
    nodeSanAntonio->neighbors.push_back(nodeSanPedrodelosPinos);
    nodeSanAntonio->neighbors.push_back(nodeMixcoacLinea7);
    nodeMixcoacLinea7->neighbors.push_back(nodeSanAntonio);
    nodeMixcoacLinea7->neighbors.push_back(nodeBarrancadelMuerto);
    nodeMixcoacLinea7->neighbors.push_back(nodeMixcoacLinea12);
    nodeBarrancadelMuerto->neighbors.push_back(nodeMixcoacLinea7);
    // linea 6
    nodeMartinCarreraLinea6->neighbors.push_back(nodeLaVillaBasílica);
    nodeMartinCarreraLinea6->neighbors.push_back(nodeMartínCarreraLinea4);
    nodeLaVillaBasílica->neighbors.push_back(nodeMartinCarreraLinea6);
    nodeLaVillaBasílica->neighbors.push_back(nodeDeportivo18DeMarzoLinea6);
    nodeDeportivo18DeMarzoLinea6->neighbors.push_back(nodeLaVillaBasílica);
    nodeDeportivo18DeMarzoLinea6->neighbors.push_back(nodeLindavista);
    nodeDeportivo18DeMarzoLinea6->neighbors.push_back(nodeDeportivo18DeMarzo);
    nodeLindavista->neighbors.push_back(nodeDeportivo18DeMarzoLinea6);
    nodeLindavista->neighbors.push_back(nodeInstitutoDelPetroleoLinea6);
    nodeInstitutoDelPetroleoLinea6->neighbors.push_back(nodeLindavista);
    nodeInstitutoDelPetroleoLinea6->neighbors.push_back(nodeVallejo);
    nodeInstitutoDelPetroleoLinea6->neighbors.push_back(nodeInstitutodelPetroleoLinea5);
    nodeVallejo->neighbors.push_back(nodeInstitutoDelPetroleoLinea6);
    nodeVallejo->neighbors.push_back(nodeNorte45);
    nodeNorte45->neighbors.push_back(nodeVallejo);
    nodeNorte45->neighbors.push_back(nodeFerreria);
    nodeFerreria->neighbors.push_back(nodeNorte45);
    nodeFerreria->neighbors.push_back(nodeAzcapotzalco);
    nodeAzcapotzalco->neighbors.push_back(nodeFerreria);
    nodeAzcapotzalco->neighbors.push_back(nodeTezozomoc);
    nodeTezozomoc->neighbors.push_back(nodeAzcapotzalco);
    nodeTezozomoc->neighbors.push_back(nodeElRosarioLinea6);
    nodeElRosarioLinea6->neighbors.push_back(nodeTezozomoc);
    nodeElRosarioLinea6->neighbors.push_back(nodeElRosarioLinea7);
    // linea 4
    nodeMartínCarreraLinea4->neighbors.push_back(nodeTalisman);
    nodeMartínCarreraLinea4->neighbors.push_back(nodeMartinCarreraLinea6);
    
    nodeTalisman->neighbors.push_back(nodeMartínCarreraLinea4);
    nodeTalisman->neighbors.push_back(nodeBondojito);

    nodeBondojito->neighbors.push_back(nodeTalisman);
    nodeBondojito->neighbors.push_back(nodeConsuladoLinea4);

    nodeConsuladoLinea4->neighbors.push_back(nodeBondojito);
    nodeConsuladoLinea4->neighbors.push_back(nodeCanalDelNorte);
    nodeConsuladoLinea4->neighbors.push_back(nodeConsuladoLinea5);

    nodeCanalDelNorte->neighbors.push_back(nodeConsuladoLinea4);
    nodeCanalDelNorte->neighbors.push_back(nodeMorelosLinea4);

    nodeMorelosLinea4->neighbors.push_back(nodeCanalDelNorte);
    nodeMorelosLinea4->neighbors.push_back(nodeCandelariaLinea4);
    nodeMorelosLinea4->neighbors.push_back(nodeMorelosLineaB);

    nodeCandelariaLinea4->neighbors.push_back(nodeMorelosLinea4);
    nodeCandelariaLinea4->neighbors.push_back(nodeFrayServando);
    nodeCandelariaLinea4->neighbors.push_back(candelaria);

    nodeFrayServando->neighbors.push_back(nodeCandelariaLinea4);
    nodeFrayServando->neighbors.push_back(nodeJamaicaLinea4);

    nodeJamaicaLinea4->neighbors.push_back(nodeFrayServando);
    nodeJamaicaLinea4->neighbors.push_back(nodeSantaAnita);
    nodeJamaicaLinea4->neighbors.push_back(nodeJamaicaLinea9);

    nodeSantaAnita->neighbors.push_back(nodeJamaicaLinea4);
    nodeSantaAnita->neighbors.push_back(nodeSantaAnitaLinea8);
    // linea 1
    graph.push_back(observatorio);
    graph.push_back(tacubayaLinea1);
    graph.push_back(juanacatlan);
    graph.push_back(chapultepec);
    graph.push_back(sevilla);
    graph.push_back(insurgentes);
    graph.push_back(cuauhtemoc);
    graph.push_back(balderas);
    graph.push_back(saltoDelAgua);
    graph.push_back(isabelLaCatolica);
    graph.push_back(pinoSuarez);
    graph.push_back(merced);
    graph.push_back(candelaria);
    graph.push_back(sanLazaro);
    graph.push_back(moctezuma);
    graph.push_back(balbuena);
    graph.push_back(boulevardPuertoAereo);
    graph.push_back(gomezFarias);
    graph.push_back(zaragoza);
    graph.push_back(pantitlanLinea1);
    // linea 5
    graph.push_back(nodePantitlanLinea5);
    graph.push_back(nodeHangares);
    graph.push_back(nodeTerminalAerea);
    graph.push_back(nodeOceaniaLinea5);
    graph.push_back(nodeAragon);
    graph.push_back(nodeEduardoMolina);
    graph.push_back(nodeConsuladoLinea5);
    graph.push_back(nodeValleGomez);
    graph.push_back(nodeMisterios);
    graph.push_back(nodeLaRazaLinea5);
    graph.push_back(nodeAutobusesdelNorte);
    graph.push_back(nodeInstitutodelPetroleoLinea5);
    graph.push_back(nodePolitecnico);
    // linea 9
    graph.push_back(nodePantitlanLinea9);
    graph.push_back(nodePuebla);
    graph.push_back(nodeCiudadDeportiva);
    graph.push_back(nodeVelodromo);
    graph.push_back(nodeMixiuhca);
    graph.push_back(nodeJamaicaLinea9);
    graph.push_back(nodeChabacanoLinea9);
    graph.push_back(nodeLazaroCardenas);
    graph.push_back(nodeCentroMedicoLinea9);
    graph.push_back(nodeChilpancingo);
    graph.push_back(nodePatriotismo);
    graph.push_back(nodeTacubayaLinea9);
    // linea 8
    graph.push_back(nodeGaribaldi);
    graph.push_back(nodeBellasArtes);
    graph.push_back(nodeSanJuanDeLetran);
    graph.push_back(nodeSaltoDelAguaLinea8);
    graph.push_back(nodeDoctores);
    graph.push_back(nodeObrera);
    graph.push_back(nodeChabacanoLinea8);
    graph.push_back(nodeLaViga);
    graph.push_back(nodeSantaAnitaLinea8);
    graph.push_back(nodeCoyuya);
    graph.push_back(nodeIztacalco);
    graph.push_back(nodeApatlaco);
    graph.push_back(nodeAculco);
    graph.push_back(nodeEscuadron201);
    graph.push_back(nodeAtlalilcoLinea8);
    graph.push_back(nodeIztapalapa);
    graph.push_back(nodeCerrodelaEstrella);
    graph.push_back(nodeUAMIztapalapa);
    graph.push_back(nodeConstitucionde1917);
    // linea 12
    graph.push_back(nodeMixcoacLinea12);
    graph.push_back(nodeInsurgentesSur);
    graph.push_back(nodeHospital20DeNoviembre);
    graph.push_back(nodeZapata);
    graph.push_back(nodeParqueDeLosVenados);
    graph.push_back(nodeEjeCentral);
    graph.push_back(nodeErmita);
    graph.push_back(nodeMexicaltzingo);
    graph.push_back(nodeAtlalilcoLinea12);
    // linea 2
    graph.push_back(nodeCuatroCaminos);
    graph.push_back(nodePanteones);
    graph.push_back(nodeTacubaLinea2);
    graph.push_back(nodeCuitlahuac);
    graph.push_back(nodePopotla);
    graph.push_back(nodeColegioMilitar);
    graph.push_back(nodeNormal);
    graph.push_back(nodeSanCosme);
    graph.push_back(nodeRevolucion);
    graph.push_back(nodeHidalgoLinea2);
    graph.push_back(nodeBellasArtesLinea2);
    graph.push_back(nodeAllende);
    graph.push_back(nodeZocalo);
    graph.push_back(nodePinoSuarezLinea2);
    graph.push_back(nodeSanAntonioAbad);
    graph.push_back(nodeChabacanoLinea2);
    graph.push_back(nodeViaducto);
    graph.push_back(nodeXola);
    graph.push_back(nodeVillaDeCortes);
    graph.push_back(nodeNativitas);
    graph.push_back(nodePortales);
    graph.push_back(nodeErmitaLinea12);
    graph.push_back(nodeGeneralAnaya);
    graph.push_back(nodeTasquena);
    // linea 3
    graph.push_back(nodeIndiosVerdes);
    graph.push_back(nodeDeportivo18DeMarzo);
    graph.push_back(nodePotrero);
    graph.push_back(nodeLaRazaLinea3);
    graph.push_back(nodeTlatelolco);
    graph.push_back(nodeGuerreroLinea3);
    graph.push_back(nodeHidalgoLinea3);
    graph.push_back(nodeJuarez);
    graph.push_back(nodeBalderasLinea3);
    graph.push_back(nodeNinosHeroes);
    graph.push_back(nodeHospitalGeneral);
    graph.push_back(nodeCentroMedicoLinea3);
    graph.push_back(nodeCentroMedicoLinea3);
    graph.push_back(nodeEtiopia);
    graph.push_back(nodeEugenia);
    graph.push_back(nodeDivisionDelNorte);
    graph.push_back(nodeZapataLinea3);
    graph.push_back(nodeCoyoacan);
    graph.push_back(nodeViveros);
    graph.push_back(nodeMiguelAngeldeQuevedo);
    graph.push_back(nodeCopilco);
    graph.push_back(nodeUniversidad);
    //linea 7
    graph.push_back(nodeElRosarioLinea7);
    graph.push_back(nodeAquilesSerdan);
    graph.push_back(nodeCamarones);
    graph.push_back(nodeRefineria);
    graph.push_back(nodeTacubaLinea7);
    graph.push_back(nodeSanJoaquin);
    graph.push_back(nodePolanco);
    graph.push_back(nodeAuditorio);
    graph.push_back(nodeConstituyentes);
    graph.push_back(nodeTacubayaLinea7);
    graph.push_back(nodeSanPedrodelosPinos);
    graph.push_back(nodeSanAntonio);
    graph.push_back(nodeMixcoacLinea7);
    graph.push_back(nodeBarrancadelMuerto);
    //linea 6
    graph.push_back(nodeMartinCarreraLinea6);
    graph.push_back(nodeLaVillaBasílica);
    graph.push_back(nodeDeportivo18DeMarzoLinea6);
    graph.push_back(nodeLindavista);
    graph.push_back(nodeInstitutoDelPetroleoLinea6);
    graph.push_back(nodeVallejo);
    graph.push_back(nodeNorte45);
    graph.push_back(nodeFerreria);
    graph.push_back(nodeAzcapotzalco);
    graph.push_back(nodeTezozomoc);
    graph.push_back(nodeElRosarioLinea6);
    // linea 4
    graph.push_back(nodeMartínCarreraLinea4);
    graph.push_back(nodeTalisman);
    graph.push_back(nodeBondojito);
    graph.push_back(nodeConsuladoLinea4);
    graph.push_back(nodeCanalDelNorte);
    graph.push_back(nodeMorelosLinea4);
    graph.push_back(nodeCandelariaLinea4);
    graph.push_back(nodeFrayServando);
    graph.push_back(nodeJamaicaLinea4);
    graph.push_back(nodeSantaAnita);

    string start_station = "Coyuya";
    string end_station = "Mixiuhca";
    cout << "Ingresa la estacion de partida: ";
    getline(cin,start_station);
    cout <<endl;
    cout << "Ingresa la estacion de destino: ";
    getline(cin,end_station);
    cout << endl;

    vector<string> shortest_path = dijkstra_shortest_path(graph, start_station, end_station, false);
    vector<string> route_instructions = get_route_instructions(shortest_path,graph);

    cout << "El camino mas corto desde " << start_station << " hasta " << end_station << " es:" << endl;
    for (const string &instruction : route_instructions)
    {
        cout << instruction << endl;
    }

    // Clean up memory
    for (Node *node : graph)
    {
        delete node;
    }

    return 0;
}
