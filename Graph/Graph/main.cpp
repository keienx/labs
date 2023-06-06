#include "header.h"

int main()
{
	system("chcp 1251 >> null");
	
	bool upravlenie = true, dejkstra = false, salesman = false, close = false;
	list<int> lst;

	graph<string> gr;
	gr.addVertex("a");
	gr.addVertex("b");
	gr.addVertex("c");
	gr.addVertex("d");
	gr.addVertex("e");
	gr.addVertex("f");
	gr.addVertex("g");
	gr.addEdge("a", "b", 7);
	gr.addDirectEdge("b", "c", 10);
	gr.addDirectEdge("c", "g", 4);
	gr.addDirectEdge("e","a", 13);
	gr.addEdge("b", "f", 17);
	gr.addEdge("c", "d", 8);
	gr.addDirectEdge("b", "f", 13);
	gr.addEdge("f", "g", 9);
	gr.addEdge("d", "a", 25);
	gr.addEdge("f", "d", 4);
	gr.addEdge("g", "e", 11);
	gr.addEdge("e", "d", 9);
	gr.addEdge("g", "d", 22);
	gr.addDirectEdge("b", "d", 13);
	vector<sf::CircleShape> v(gr.size());
	vector<sf::RectangleShape> v_edges;
	vector<sf::Text> v_text;
	vector<sf::Text> v_weight;
	vector<sf::Text> v_dejkstra;
	vector<int> for_dejk;
	//�������/�����
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(18);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	text.setOutlineColor(sf::Color::Green);
	text.setOutlineThickness(2);

	//�����/�����
	sf::Font font_weight;
	font_weight.loadFromFile("arial.ttf");
	sf::Text text_weight;
	text_weight.setFont(font_weight);
	text_weight.setCharacterSize(22);
	text_weight.setFillColor(sf::Color::Black);
	text_weight.setStyle(sf::Text::Bold);
	text_weight.setOutlineColor(sf::Color::White);
	text_weight.setOutlineThickness(4);

	vector<sf::ConvexShape> v_direction;
	cordCalculate(v, gr.size());
	gr.calcCordEdge(v_edges, v_direction,v);
	gr.calcCordText(v_text, v, text);
	gr.calcCordWeight(v_weight, v, text_weight);
	
	//����
	size_t temp_size = gr.size();
	sf::Color color(255, 255, 255);	
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Graph");
	window.setFramerateLimit(60);

	thread t([&upravlenie, &gr, &dejkstra, &for_dejk, &window, &salesman, &lst, & close](){	//������������ ����� ��� ���������� ������
		auto vector_my = gr.getVertexData();
		string menu;
		string data, data2;
		int menu_control;
		int weight;
		vector<string>::iterator it;
		menu = "1. �������� �������\n2. ������� �������\n3. �������� �������������� �����\n"
			"4. �������� ������������ �����\n5. ������� �����\n6. ������� ������ ������������\n7. �������� ��������\n8. ����� � ������\n9. ����� � �������\n0. ���������� ������ ���������";

		while (true){
			cout << menu << "\n";
			cin >> menu_control;
			if (!window.isOpen()) {
				return;
			}
			switch (menu_control){
			case 1:
				cout << "������� �������� �������: " << "\n"; cin >> data;
				gr.addVertex(data);
				upravlenie = true;
				break;
			case 2:
				cout << "������� �������� �������: " << "\n"; cin >> data;
				gr.removeVertex(data);
				upravlenie = true;
				break;
			case 3:
				cout << "������� ��� ������� �������: " << "\n"; cin >> data; cin >> data2;
				cout << "������� ��� �����: " << "\n"; cin >> weight;
				gr.addEdge(data, data2, weight);
				upravlenie = true;
				break;
			case 4:
				cout << "������� ��� ������� �������: " << "\n"; cin >> data; cin >> data2;
				cout << "������� ��� �����: " << "\n"; cin >> weight;
				gr.addDirectEdge(data, data2, weight);
				upravlenie = true;
				break;
			case 5:
				cout << "������� ��� ������� �������, ����� ����� �������� ���������� �������: " << "\n"; cin >> data; cin >> data2;
				gr.removeEdge(data, data2);
				upravlenie = true;
				break;
			case 6:
				cout << "������� ��������� �������: " << "\n"; cin >> data;
				vector_my = gr.getVertexData();
				it = find(vector_my.begin(), vector_my.end(), data);
				if (it == vector_my.end()){
					cout << "\n" << "\n" << "������� �����������." << "\n";
					system("pause");
					break;
				}
				gr.SalesmanTravel(distance(vector_my.begin(), it));
				lst = gr.getPath();
				if(lst.size() != vector_my.size()){
					cout << "\n" << "\n" << "������� ������ ������������ ��� ������� ����� �� ����������." << "\n";
					system("pause");
				}
				else{
					cout << "\n" << "����:" << "\n";
					for (auto& i : lst){
						cout << vector_my[i] << " -> ";
					}
					cout << vector_my[lst.front()] << "\n";
					cout << "����������: " << gr.getPathWeight() << "\n" << "\n";
					salesman = true;
					system("pause");
					salesman = false;
				}
				break;
			case 7:
				vector_my = gr.getVertexData();
				cout << "������� ��������� �������: " << endl << "> "; cin >> data;
				it = find(vector_my.begin(), vector_my.end(), data);
				if (it == vector_my.end())
				{
					cout << endl << endl << "������ ������� �� ����������." << endl;
					system("pause");
				}
				else
				{
					for_dejk = gr.dijkstra(size_t(distance(vector_my.begin(), it)));
					dejkstra = true;
					system("pause");
					dejkstra = false;
				}
				break;
			case 8:
				cout << "������� ��������� �������: " << endl << "> "; cin >> data;
				cout << "����� � ������:" << endl;
				if (!gr.BFSHelper(data))
				{
					system("cls");
					cout << "������ ������� �� ����������." << endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			case 9:
				cout << "������� ��������� �������: " << endl << "> "; cin >> data;
				cout << "����� � �������:" << endl;
				if (!gr.DFSHelper(data))
				{
					system("cls");
					cout << "������ ������� �� ����������." << endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			default:
				menu_control = 0;
				break;
			}
			system("cls");
			string fl;			
		}
		
	});

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) 
			if (event.type == sf::Event::Closed || !t.joinable()) {
				window.close();
				t.join();
			}
		if (upravlenie){
			upravlenie = false;
			temp_size = gr.size();
			cordCalculate(v, temp_size);
			gr.calcCordEdge(v_edges, v_direction, v);
			gr.calcCordText(v_text, v, text);
			gr.calcCordWeight(v_weight, v, text_weight);
		}

		if (salesman){
			vector<sf::CircleShape> v_point;
			vector<sf::CircleShape> v_path;	
			v_path.reserve(800);
			sf::CircleShape trailShape(5.0f);
			trailShape.setFillColor(sf::Color::Black);
			trailShape.setOrigin(trailShape.getLocalBounds().width / 2, trailShape.getLocalBounds().height / 2);

			sf::Image image;					
			image.loadFromFile("images/triangle.png");
			image.createMaskFromColor(sf::Color(255, 255, 255));
			sf::Texture triangle;
			triangle.loadFromImage(image);
			sf::Sprite triangle_sp;
			triangle_sp.setTexture(triangle);
			triangle_sp.setScale(0.07f, 0.07f);
			triangle_sp.setOrigin(triangle_sp.getLocalBounds().width / 2.0f, triangle_sp.getLocalBounds().height / 2.0f);

			const float animationSpeed = 700.0f;
			sf::Clock clock;
			float elapsedTime = 0.0f;
			int current_local, next_local;
			sf::Vector2f temp;
			auto lst_temp = gr.getPath();
			int size_temp = lst_temp.size();
			next_local = lst_temp.front();


			for (size_t i = 1; i < size_temp; ++i){
				elapsedTime = 0.0f;

				current_local = next_local;
				lst_temp.pop_front();
				next_local = lst_temp.front();

				v_point.push_back(v[current_local]);
				v_point[i - 1].setOutlineColor(sf::Color::Black);
				v_point[i - 1].setOutlineThickness(9);

				//��������� �������
				temp = v[current_local].getPosition() - v[next_local].getPosition();
				triangle_sp.setPosition(v[current_local].getPosition());
				triangle_sp.setRotation((atan2(temp.y, temp.x) * 180 / 3.14159) - 90);

				sf::Vector2f startPosition = v[current_local].getPosition();
				sf::Vector2f targetPosition = v[next_local].getPosition();
				sf::Vector2f distance = targetPosition - startPosition;
				float totalDistance = std::sqrt(distance.x * distance.x + distance.y * distance.y);
				float travelTime = totalDistance / animationSpeed;
				
				if (!salesman) break;
				while (elapsedTime < travelTime) {
					clock.restart();
					window.clear(color);
					if (!salesman) break;
					for (int j = 0; j < v_point.size(); j++){
						window.draw(v_point[j]);
					}
					for (int j = 0; j < v_edges.size(); j++){
						window.draw(v_edges[j]);
						window.draw(v_direction[j]);
					}
					for (int j = 0; j < v_path.size(); j++){
						window.draw(v_path[j]);
					}
					for (int j = 0; j < v.size(); j++){
						window.draw(v[j]);
						window.draw(v_text[j]);
					}
					for (int j = 0; j < v_weight.size(); j++){
						window.draw(v_weight[j]);
					}

					window.draw(triangle_sp);
					window.display();

					elapsedTime += clock.getElapsedTime().asSeconds();

					float t = elapsedTime / travelTime;
					sf::Vector2f currentPosition = startPosition + distance * t;
					trailShape.setPosition(triangle_sp.getPosition());
					v_path.push_back(trailShape);
					triangle_sp.setPosition(currentPosition);
					travelTime = totalDistance / animationSpeed;
					sf::sleep(sf::milliseconds(10));
				}
			}

			v_point.push_back(v[next_local]);
			v_point.back().setOutlineColor(sf::Color::Black);
			v_point.back().setOutlineThickness(9);


			if (salesman){
				elapsedTime = 0.0f;
				lst_temp = gr.getPath();
				temp = v[lst_temp.back()].getPosition() - v[lst_temp.front()].getPosition();
				triangle_sp.setPosition(v[lst_temp.back()].getPosition());
				triangle_sp.setRotation((atan2(temp.y, temp.x) * 180 / 3.14159) - 90);

				sf::Vector2f startPosition = v[lst_temp.back()].getPosition();
				sf::Vector2f targetPosition = v[lst_temp.front()].getPosition();
				sf::Vector2f distance = targetPosition - startPosition;
				float totalDistance = std::sqrt(distance.x * distance.x + distance.y * distance.y);
				float travelTime = totalDistance / animationSpeed;

				if (!salesman) {
					break;
				}

				while (elapsedTime < travelTime){
					clock.restart();
					window.clear(color);
					if (!salesman) break;
					for (int j = 0; j < v_point.size(); j++){
						window.draw(v_point[j]);
					}
					for (int j = 0; j < v_edges.size(); j++){
						window.draw(v_edges[j]);
						window.draw(v_direction[j]);
					}
					for (int j = 0; j < v_path.size(); j++){
						window.draw(v_path[j]);
					}
					for (int j = 0; j < v.size(); j++){
						window.draw(v[j]);
						window.draw(v_text[j]);
					}
					for (int j = 0; j < v_weight.size(); j++){
						window.draw(v_weight[j]);
					}

					window.draw(triangle_sp);
					window.display();

					elapsedTime += clock.getElapsedTime().asSeconds();

					float t = elapsedTime / travelTime;
					sf::Vector2f currentPosition = startPosition + distance * t;
					trailShape.setPosition(triangle_sp.getPosition());
					v_path.push_back(trailShape);
					triangle_sp.setPosition(currentPosition);
					travelTime = totalDistance / animationSpeed;
					sf::sleep(sf::milliseconds(10));
				}
				while (salesman){
					sf::sleep(sf::milliseconds(5));
				}
			}
		}
		else{
			if (dejkstra){
				gr.calcCordDijkstra(v_dejkstra, v, for_dejk, text);
			}
			window.clear(color);

			for (int i = 0; i < v_edges.size(); i++){
				window.draw(v_edges[i]);
				window.draw(v_direction[i]);
			}

			for (int i = 0; i < v.size(); i++){
				window.draw(v[i]);
			}
			for (int i = 0; i < v_text.size(); i++){
				window.draw(v_text[i]);
			}
			for (int i = 0; i < v_weight.size(); i++){
				window.draw(v_weight[i]);
			}
			if (dejkstra)
			{
				for (int i = 0; i < v_dejkstra.size(); i++)
					window.draw(v_dejkstra[i]);
			}
		}
		

		window.display();
			sf::sleep(sf::milliseconds(5));
	}

	

	return 0;
}
 

//����������� ������
void cordCalculate(vector <sf::CircleShape>& vec, size_t new_size){
	if (new_size == 0){
		vec.clear();
		return;
	}
	float width, height;
	vec.clear();
	sf::CircleShape circle(40);
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineThickness(3);
	circle.setOutlineColor(sf::Color::Magenta);
	float radius = 350.f;
	sf::Vector2f center = { 500.f, 500.f };
	float currentAngle = 0.f;
	float angleStep = 360.f / new_size;
	for (int i = 0; i < new_size; i++){
		circle.setPosition(center.x + radius * std::cos(currentAngle * 3.14159 / 180.f), center.y + radius * std::sin(currentAngle * 3.14159 / 180.f));
		currentAngle += angleStep;
		width = circle.getLocalBounds().width;
		height = circle.getLocalBounds().height;
		circle.setOrigin(width / 2.0f, height / 2.0f);
		vec.push_back(circle);
	}
}