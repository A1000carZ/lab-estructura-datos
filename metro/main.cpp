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
    Node *transfer_6;

    Node(string name, string line) : name(name), line(line), transfer_1(NULL), transfer_2(NULL), transfer_3(NULL), transfer_4(NULL), transfer_5(NULL), transfer_6(NULL) {}
};

typedef pair<int, Node *> pin; // pair of (weight, node)

vector<string> dijkstra_shortest_path(vector<Node *> graph, string start, string end)
{
    vector<int> distances(graph.size(), numeric_limits<int>::max());
    vector<string> previous(graph.size(), "");
    priority_queue<pin, vector<pin>, greater<pin> > pq;

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
        if (current_node->transfer_6 != NULL)
        {
            int weight = 1; // Assuming equal weight for all connections
            int distance = current_distance + weight;
            int neighborIdx = current_node->transfer_6 - graph[0];

            if (distance < distances[neighborIdx - 1])
            {
                distances[neighborIdx - 1] = distance;
                previous[neighborIdx - 1] = current_node->name;
                pq.push(make_pair(distance, current_node->transfer_3));
            }
        }

        for (int i = 0; i < graph.size(); ++i)
        {
            if (graph[i]->transfer_1 == current_node)
            {
                int weight = 1; // Assuming equal weight for all connections
                int distance = current_distance + weight;

                if (distance < distances[i])
                {
                    distances[i] = distance;
                    previous[i] = current_node->name;
                    pq.push(make_pair(distance, graph[i]));
                }
            }

            if (graph[i]->transfer_2 == current_node)
            {
                int weight = 1; // Assuming equal weight for all connections
                int distance = current_distance + weight;

                if (distance < distances[i])
                {
                    distances[i] = distance;
                    previous[i] = current_node->name;
                    pq.push(make_pair(distance, graph[i]));
                }
            }

            if (graph[i]->transfer_3 == current_node)
            {
                int weight = 1; // Assuming equal weight for all connections
                int distance = current_distance + weight;

                if (distance < distances[i])
                {
                    distances[i] = distance;
                    previous[i] = current_node->name;
                    pq.push(make_pair(distance, graph[i]));
                }
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
    Node *nodeBalderasLinea1 = new Node("Balderas", "Linea 1");
    Node *nodeSaltoDelAguaLinea1 = new Node("Salto del Agua", "Linea 1");
    Node *nodeIsabelLaCatolica = new Node("Isabel la Catolica", "Linea 1");
    Node *nodePinoSuarezLinea1 = new Node("Pino Suarez", "Linea 1");
    Node *nodeMerced = new Node("Merced", "Linea 1");
    Node *nodeCandelariaLinea1 = new Node("Candelaria", "Linea 1");
    Node *nodeSanLazaroLinea1 = new Node("San Lazaro", "Linea 1");
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
    Node *nodeOceaniaLinea5 = new Node("Oceania", "Linea 5");
    Node *nodeAragon = new Node("Aragon", "Linea 5");
    Node *nodeEduardoMolina = new Node("Eduardo Molina", "Linea 5");
    Node *nodeConsuladoLinea5 = new Node("Consulado", "Linea 5");
    Node *nodeValleGomez = new Node("Valle Gomez", "Linea 5");
    Node *nodeMisterios = new Node("Misterios", "Linea 5");
    Node *nodeLaRazaLinea5 = new Node("La Raza", "Linea 5");
    Node *nodeAutobusesdelNorte = new Node("Autobuses del Norte", "Linea 5");
    Node *nodeInstitutodelPetroleoLinea5 = new Node("Instituto del Petroleo", "Linea 5");
    Node *nodePolitecnico = new Node("Politecnico", "Linea 5");

    // Línea 9
    Node *nodeTacubayaLinea9 = new Node("Tacubaya", "Linea 9");
    Node *nodePatriotismo = new Node("Patriotismo", "Linea 9");
    Node *nodeChilpancingo = new Node("Chilpancingo", "Linea 9");
    Node *nodeCentroMedicoLinea9 = new Node("Centro Medico", "Linea 9");
    Node *nodeLazaroCardenas = new Node("Lazaro Cardenas", "Linea 9");
    Node *nodeChabacanoLinea9 = new Node("Chabacano", "Linea 9");
    Node *nodeJamaicaLinea9 = new Node("Jamaica", "Linea 9");
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
    Node *nodeSantaAnitaLinea8 = new Node("Santa Anita", "Linea 8");
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
    Node *nodeLaRazaLinea3 = new Node("La Raza", "Linea 3");
    Node *nodeTlatelolco = new Node("Tlatelolco", "Linea 3");
    Node *nodeGuerreroLinea3 = new Node("Guerrero", "Linea 3");
    Node *nodeHidalgoLinea3 = new Node("Hidalgo", "Linea 3");
    Node *nodeJuarez = new Node("Juarez", "Linea 3");
    Node *nodeBalderasLinea3 = new Node("Balderas", "Linea 3");
    Node *nodeNinosHeroes = new Node("Ninos Heroes", "Linea 3");
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
    nodeTacubayaLinea1->transfer_3 = nodeConstituyentes;
    nodeTacubayaLinea1->transfer_4 = nodeSanPedrodelosPinos;
    nodeTacubayaLinea1->transfer_5 = nodePatriotismo;

    nodeJuanacatlan->transfer_1 = nodeTacubayaLinea1;
    nodeJuanacatlan->transfer_2 = nodeChapultepec;

    nodeChapultepec->transfer_1 = nodeJuanacatlan;
    nodeChapultepec->transfer_2 = nodeSevilla;

    nodeSevilla->transfer_1 = nodeChapultepec;
    nodeSevilla->transfer_2 = nodeInsurgentes;

    nodeInsurgentes->transfer_1 = nodeSevilla;
    nodeInsurgentes->transfer_2 = nodeCuauhtemoc;

    nodeCuauhtemoc->transfer_1 = nodeInsurgentes;
    nodeCuauhtemoc->transfer_2 = nodeBalderasLinea1;

    nodeBalderasLinea1->transfer_1 = nodeCuauhtemoc;
    nodeBalderasLinea1->transfer_2 = nodeSaltoDelAguaLinea1;
    nodeBalderasLinea1->transfer_3 = nodeJuarez;
    nodeBalderasLinea1->transfer_4 = nodeNinosHeroes;

    nodeSaltoDelAguaLinea1->transfer_1 = nodeBalderasLinea1;
    nodeSaltoDelAguaLinea1->transfer_2 = nodeIsabelLaCatolica;
    nodeSaltoDelAguaLinea1->transfer_3 = nodeSanJuanDeLetran;
    nodeSaltoDelAguaLinea1->transfer_4 = nodeDoctores;

    nodeIsabelLaCatolica->transfer_1 = nodeSaltoDelAguaLinea1;
    nodeIsabelLaCatolica->transfer_2 = nodePinoSuarezLinea1;

    nodePinoSuarezLinea1->transfer_1 = nodeIsabelLaCatolica;
    nodePinoSuarezLinea1->transfer_2 = nodeMerced;
    nodePinoSuarezLinea1->transfer_3 = nodeZocalo;
    nodePinoSuarezLinea1->transfer_4 = nodeSanAntonioAbad;

    nodeMerced->transfer_1 = nodePinoSuarezLinea1;
    nodeMerced->transfer_2 = nodeCandelariaLinea1;

    nodeCandelariaLinea1->transfer_1 = nodeMerced;
    nodeCandelariaLinea1->transfer_2 = nodeSanLazaroLinea1;
    nodeCandelariaLinea1->transfer_3 = nodeMorelosLinea4;
    nodeCandelariaLinea1->transfer_4 = nodeFrayServando;

    nodeSanLazaroLinea1->transfer_1 = nodeCandelariaLinea1;
    nodeSanLazaroLinea1->transfer_2 = nodeMoctezuma;
    nodeSanLazaroLinea1->transfer_3 = nodeMorelosLineaB;
    nodeSanLazaroLinea1->transfer_4 = nodeRicardoFloresMagon;

    nodeMoctezuma->transfer_1 = nodeSanLazaroLinea1;
    nodeMoctezuma->transfer_2 = nodeBalbuena;

    nodeBalbuena->transfer_1 = nodeMoctezuma;
    nodeBalbuena->transfer_2 = nodeBoulevardPtoAereo;

    nodeBoulevardPtoAereo->transfer_1 = nodeBalbuena;
    nodeBoulevardPtoAereo->transfer_2 = nodeGomezFarias;

    nodeGomezFarias->transfer_1 = nodeBoulevardPtoAereo;
    nodeGomezFarias->transfer_2 = nodeZaragoza;

    nodeZaragoza->transfer_1 = nodeGomezFarias;
    nodeZaragoza->transfer_1 = nodePantitlanLinea1;

    nodePantitlanLinea1->transfer_1 = nodeZaragoza;
    nodePantitlanLinea1->transfer_2 = nodePantitlanLinea5;
    nodePantitlanLinea1->transfer_2 = nodePantitlanLinea9;

    // Línea 5
    nodePantitlanLinea5->transfer_1 = nodeHangares;
    nodePantitlanLinea5->transfer_2 = nodePantitlanLinea1;
    nodePantitlanLinea5->transfer_3 = nodePantitlanLinea9;

    nodeHangares->transfer_1 = nodeTerminalAerea;
    nodeHangares->transfer_2 = nodePantitlanLinea5;

    nodeTerminalAerea->transfer_1 = nodeHangares;
    nodeTerminalAerea->transfer_2 = nodeOceaniaLinea5;

    nodeOceaniaLinea5->transfer_1 = nodeTerminalAerea;
    nodeOceaniaLinea5->transfer_2 = nodeAragon;
    nodeOceaniaLinea5->transfer_3 = nodeDeportivoOceania;
    nodeOceaniaLinea5->transfer_4 = nodeRomeroRubio;

    nodeAragon->transfer_1 = nodeOceaniaLinea5;
    nodeAragon->transfer_2 = nodeEduardoMolina;

    nodeEduardoMolina->transfer_1 = nodeAragon;
    nodeEduardoMolina->transfer_2 = nodeConsuladoLinea5;

    nodeConsuladoLinea5->transfer_1 = nodeEduardoMolina;
    nodeConsuladoLinea5->transfer_2 = nodeValleGomez;
    nodeConsuladoLinea5->transfer_3 = nodeBondojito;
    nodeConsuladoLinea5->transfer_4 = nodeCanalDelNorte;

    nodeValleGomez->transfer_1 = nodeConsuladoLinea5;
    nodeValleGomez->transfer_2 = nodeMisterios;

    nodeMisterios->transfer_1 = nodeValleGomez;
    nodeMisterios->transfer_2 = nodeLaRazaLinea5;

    nodeLaRazaLinea5->transfer_1 = nodeAutobusesdelNorte;
    nodeLaRazaLinea5->transfer_2 = nodeMisterios;
    nodeLaRazaLinea5->transfer_3 = nodeTlatelolco;
    nodeLaRazaLinea5->transfer_4 = nodePotrero;

    nodeAutobusesdelNorte->transfer_1 = nodeInstitutodelPetroleoLinea5;
    nodeAutobusesdelNorte->transfer_2 = nodeLaRazaLinea5;

    nodeInstitutodelPetroleoLinea5->transfer_1 = nodePolitecnico;
    nodeInstitutodelPetroleoLinea5->transfer_2 = nodeAutobusesdelNorte;
    nodeInstitutodelPetroleoLinea5->transfer_3 = nodeVallejo;
    nodeInstitutodelPetroleoLinea5->transfer_3 = nodeLindavista;

    nodePolitecnico->transfer_1 = nodeInstitutodelPetroleoLinea5;

    // Línea 9
    nodeTacubayaLinea9->transfer_1 = nodePatriotismo;
    nodeTacubayaLinea9->transfer_2 = nodeObservatorio;
    nodeTacubayaLinea9->transfer_3 = nodeConstituyentes;
    nodeTacubayaLinea9->transfer_4 = nodeSanPedrodelosPinos;

    nodePatriotismo->transfer_1 = nodeTacubayaLinea9;
    nodePatriotismo->transfer_2 = nodeChilpancingo;

    nodeChilpancingo->transfer_1 = nodePatriotismo;
    nodeChilpancingo->transfer_2 = nodeCentroMedicoLinea9;

    nodeCentroMedicoLinea9->transfer_1 = nodeChilpancingo;
    nodeCentroMedicoLinea9->transfer_2 = nodeLazaroCardenas;
    nodeCentroMedicoLinea9->transfer_3 = nodeHospitalGeneral;
    nodeCentroMedicoLinea9->transfer_4 = nodeEtiopia;

    nodeLazaroCardenas->transfer_1 = nodeCentroMedicoLinea9;
    nodeLazaroCardenas->transfer_2 = nodeChabacanoLinea9;

    nodeChabacanoLinea9->transfer_1 = nodeLazaroCardenas;
    nodeChabacanoLinea9->transfer_2 = nodeJamaicaLinea9;
    nodeChabacanoLinea9->transfer_3 = nodeObrera;
    nodeChabacanoLinea9->transfer_4 = nodeSanAntonioAbad;
    nodeChabacanoLinea9->transfer_5 = nodeViaducto;
    nodeChabacanoLinea9->transfer_6 = nodeLaViga;

    nodeJamaicaLinea9->transfer_1 = nodeChabacanoLinea9;
    nodeJamaicaLinea9->transfer_2 = nodeMixiuhca;
    nodeJamaicaLinea9->transfer_3 = nodeSantaAnitaLinea8;
    nodeJamaicaLinea9->transfer_4 = nodeFrayServando;

    nodeMixiuhca->transfer_1 = nodeJamaicaLinea9;
    nodeMixiuhca->transfer_2 = nodeVelodromo;

    nodeVelodromo->transfer_1 = nodeMixiuhca;
    nodeVelodromo->transfer_2 = nodeCiudadDeportiva;

    nodeCiudadDeportiva->transfer_1 = nodeVelodromo;
    nodeCiudadDeportiva->transfer_2 = nodePuebla;

    nodePuebla->transfer_1 = nodeCiudadDeportiva;
    nodePuebla->transfer_2 = nodePantitlanLinea9;

    nodePantitlanLinea9->transfer_1 = nodePantitlanLinea1;
    nodePantitlanLinea9->transfer_2 = nodePantitlanLinea5;

    graph.push_back(nodeObservatorio);
    graph.push_back(nodeTacubayaLinea1);
    graph.push_back(nodeJuanacatlan);
    graph.push_back(nodeChapultepec);
    graph.push_back(nodeSevilla);
    graph.push_back(nodeInsurgentes);
    graph.push_back(nodeCuauhtemoc);
    graph.push_back(nodeBalderasLinea1);
    graph.push_back(nodeSaltoDelAguaLinea1);
    graph.push_back(nodeIsabelLaCatolica);
    graph.push_back(nodePinoSuarezLinea1);
    graph.push_back(nodeMerced);
    graph.push_back(nodeCandelariaLinea1);
    graph.push_back(nodeSanLazaroLinea1);
    graph.push_back(nodeMoctezuma);
    graph.push_back(nodeBalbuena);
    graph.push_back(nodeBoulevardPtoAereo);
    graph.push_back(nodeGomezFarias);
    graph.push_back(nodeZaragoza);
    graph.push_back(nodePantitlanLinea1);

    string start_station = "Gomez Farias";
    string end_station = "Balbuena";

    vector<string> shortest_path = dijkstra_shortest_path(graph, start_station, end_station);

    cout << "Shortest path from " << start_station << " to " << end_station << ":" << endl;
    for (int i = 0; i < shortest_path.size() - 1; i++)
    {
        cout << shortest_path[i] << " (" << graph[i]->line << ") -> ";
    }
    cout << shortest_path.back() << endl;

    return 0;
}
