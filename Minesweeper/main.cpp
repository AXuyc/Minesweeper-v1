#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>

using namespace std::chrono;


class GridMap : public sf::Drawable, public sf::Transformable
{
public:
    void load(const std::filesystem::path& tileset, int width, int height, int tileSize) {
        //load creates the vertices array which all of the tiles will be rendered

        m_tileset.loadFromFile(tileset);


        //Resizing size of m_vertices to fit in all coordinates
        m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
        m_vertices.resize(width * height * 6);

        
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {

                sf::Vertex* triangles = &m_vertices[(i + j * width) * 6];

                triangles[0].position = sf::Vector2f(i * tileSize, j * tileSize);
                triangles[1].position = sf::Vector2f((i + 1) * tileSize, j * tileSize);
                triangles[2].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize);
                triangles[3].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize);
                triangles[4].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize);
                triangles[5].position = sf::Vector2f(i * tileSize, j * tileSize);

                
                triangles[0].texCoords = sf::Vector2f(17,32);
                triangles[1].texCoords = sf::Vector2f(117,32);
                triangles[2].texCoords = sf::Vector2f(117,132);
                triangles[3].texCoords = sf::Vector2f(117,132);
                triangles[4].texCoords = sf::Vector2f(17,132);
                triangles[5].texCoords = sf::Vector2f(17,32);


            }
        }

    }

    void update(std::vector<std::vector<int>>& mine_map, int width, int height) {
        //update reads the entire grid and updates textures to tiles that have changed
       

        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                sf::Vertex* triangles = &m_vertices[(i + j * width) * 6];
                switch (mine_map[i][j]) {
                case 0:
                    triangles[0].texCoords = sf::Vector2f(17, 32);
                    triangles[1].texCoords = sf::Vector2f(117, 32);
                    triangles[2].texCoords = sf::Vector2f(117, 132);
                    triangles[3].texCoords = sf::Vector2f(117, 132);
                    triangles[4].texCoords = sf::Vector2f(17, 132);
                    triangles[5].texCoords = sf::Vector2f(17, 32);
                    break;
                case 1:
                    triangles[0].texCoords = sf::Vector2f(17, 32);
                    triangles[1].texCoords = sf::Vector2f(117, 32);
                    triangles[2].texCoords = sf::Vector2f(117, 132);
                    triangles[3].texCoords = sf::Vector2f(117, 132);
                    triangles[4].texCoords = sf::Vector2f(17, 132);
                    triangles[5].texCoords = sf::Vector2f(17, 32);
                    break;
                case 2:
                    triangles[0].texCoords = sf::Vector2f(267, 32);
                    triangles[1].texCoords = sf::Vector2f(267 + 100, 32);
                    triangles[2].texCoords = sf::Vector2f(267 + 100, 32 + 100);
                    triangles[3].texCoords = sf::Vector2f(267 + 100, 32 + 100);
                    triangles[4].texCoords = sf::Vector2f(267, 32 + 100);
                    triangles[5].texCoords = sf::Vector2f(267, 32);
                    break;
                case 3:
                    triangles[0].texCoords = sf::Vector2f(267, 32);
                    triangles[1].texCoords = sf::Vector2f(267 + 100, 32);
                    triangles[2].texCoords = sf::Vector2f(267 + 100, 32 + 100);
                    triangles[3].texCoords = sf::Vector2f(267 + 100, 32 + 100);
                    triangles[4].texCoords = sf::Vector2f(267, 32 + 100);
                    triangles[5].texCoords = sf::Vector2f(267, 32);
                    break;
                case 10:
                    triangles[0].texCoords = sf::Vector2f(143, 32);
                    triangles[1].texCoords = sf::Vector2f(143 + 100, 32);
                    triangles[2].texCoords = sf::Vector2f(143 + 100, 32 + 100);
                    triangles[3].texCoords = sf::Vector2f(143 + 100, 32 + 100);
                    triangles[4].texCoords = sf::Vector2f(143, 32 + 100);
                    triangles[5].texCoords = sf::Vector2f(143, 32);
                    break;
                case 11:
                    triangles[0].texCoords = sf::Vector2f(19, 357);
                    triangles[1].texCoords = sf::Vector2f(19 + 100, 357);
                    triangles[2].texCoords = sf::Vector2f(19 + 100, 357 + 100);
                    triangles[3].texCoords = sf::Vector2f(19 + 100, 357 + 100);
                    triangles[4].texCoords = sf::Vector2f(19, 357 + 100);
                    triangles[5].texCoords = sf::Vector2f(19, 357);
                    break;
                case 12:
                    triangles[0].texCoords = sf::Vector2f(391, 32);
                    triangles[1].texCoords = sf::Vector2f(391 + 100, 32);
                    triangles[2].texCoords = sf::Vector2f(391 + 100, 32 + 100);
                    triangles[3].texCoords = sf::Vector2f(391 + 100, 32 + 100);
                    triangles[4].texCoords = sf::Vector2f(391, 32 + 100);
                    triangles[5].texCoords = sf::Vector2f(391, 32);
                    break;
                case 13:
                    triangles[0].texCoords = sf::Vector2f(18, 201);
                    triangles[1].texCoords = sf::Vector2f(18 + 100, 201);
                    triangles[2].texCoords = sf::Vector2f(18 + 100, 201 + 100);
                    triangles[3].texCoords = sf::Vector2f(18 + 100, 201 + 100);
                    triangles[4].texCoords = sf::Vector2f(18, 201 + 100);
                    triangles[5].texCoords = sf::Vector2f(18, 201);
                    break;
                case 14:
                    triangles[0].texCoords = sf::Vector2f(144, 201);
                    triangles[1].texCoords = sf::Vector2f(144 + 100, 201);
                    triangles[2].texCoords = sf::Vector2f(144 + 100, 201 + 100);
                    triangles[3].texCoords = sf::Vector2f(144 + 100, 201 + 100);
                    triangles[4].texCoords = sf::Vector2f(144, 201 + 100);
                    triangles[5].texCoords = sf::Vector2f(144, 201);
                    break;
                case 15:
                    triangles[0].texCoords = sf::Vector2f(267, 201);
                    triangles[1].texCoords = sf::Vector2f(267 + 100, 201);
                    triangles[2].texCoords = sf::Vector2f(267 + 100, 201 + 100);
                    triangles[3].texCoords = sf::Vector2f(267 + 100, 201 + 100);
                    triangles[4].texCoords = sf::Vector2f(267, 201 + 100);
                    triangles[5].texCoords = sf::Vector2f(267, 201);
                    break;
                case 16:
                    triangles[0].texCoords = sf::Vector2f(392, 201);
                    triangles[1].texCoords = sf::Vector2f(392 + 100, 201);
                    triangles[2].texCoords = sf::Vector2f(392 + 100, 201 + 100);
                    triangles[3].texCoords = sf::Vector2f(392 + 100, 201 + 100);
                    triangles[4].texCoords = sf::Vector2f(392, 201 + 100);
                    triangles[5].texCoords = sf::Vector2f(392, 201);
                    break;
                case 17:
                    triangles[0].texCoords = sf::Vector2f(145, 356);
                    triangles[1].texCoords = sf::Vector2f(145 + 100, 356);
                    triangles[2].texCoords = sf::Vector2f(145 + 100, 356 + 100);
                    triangles[3].texCoords = sf::Vector2f(145 + 100, 356 + 100);
                    triangles[4].texCoords = sf::Vector2f(145, 356 + 100);
                    triangles[5].texCoords = sf::Vector2f(145, 356);
                    break;
                case 18:
                    triangles[0].texCoords = sf::Vector2f(268, 256);
                    triangles[1].texCoords = sf::Vector2f(268 + 100, 256);
                    triangles[2].texCoords = sf::Vector2f(268 + 100, 256 + 100);
                    triangles[3].texCoords = sf::Vector2f(268 + 100, 256 + 100);
                    triangles[4].texCoords = sf::Vector2f(268, 256 + 100);
                    triangles[5].texCoords = sf::Vector2f(268, 256);
                    break;
                case 20:
                    triangles[0].texCoords = sf::Vector2f(393, 357);
                    triangles[1].texCoords = sf::Vector2f(393 + 100, 357);
                    triangles[2].texCoords = sf::Vector2f(393 + 100, 357 + 100);
                    triangles[3].texCoords = sf::Vector2f(393 + 100, 357 + 100);
                    triangles[4].texCoords = sf::Vector2f(393, 357 + 100);
                    triangles[5].texCoords = sf::Vector2f(393, 357);
                    break;
                }
            }
        }
    }
    void reset(std::vector<std::vector<int>>& mine_map, int width, int height, int mine_num, int max_width, int max_height) {
        //Reset the grid back to default and generates a new map. 


        //The
        for (int i = 0; i < max_width; i++) {
            for (int j = 0; j < max_height; j++) {
                mine_map[i][j] = 100;
            }
        }

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                mine_map[i][j] = 0;
            }
        }
        
        std::srand(std::time(0));

        int num = 0;
        while (num < mine_num) {
            int x = rand() % width;
            int y = rand() % height;
            if (mine_map[x][y] != 1) {
                mine_map[x][y] = 1;
                num++;
            }
        }
    }
    

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture     m_tileset;
};



int count_mine(std::vector<std::vector<int>>& mine_map, int x, int y) {
    //Count the total number of mines in the surrounding tiles of the tile
    int num = 0;
    int row[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int col[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    for (int i = 0; i < 8; i++) {
        int nrow = x + row[i];
        int ncol = y + col[i];

        if (nrow >= 0 and nrow < mine_map.size() and ncol >= 0 and ncol < mine_map[0].size()) {
            if (mine_map[nrow][ncol] == 1 or mine_map[nrow][ncol] == 3) {
                num++;
            }
        }
    }
    return num;
}

void dfs(std::vector<std::vector<int>>& mine_map, int x, int y) {
    if (x < 0 or x >= mine_map.size() or y < 0 or y >= mine_map[0].size() or mine_map[x][y] != 0) {
        return;
    }

    int mine_num = count_mine(mine_map, x, y);

    switch (mine_num) {
    case 0:
        mine_map[x][y] = 10;
        dfs(mine_map, x - 1, y - 1);
        dfs(mine_map, x, y - 1);
        dfs(mine_map, x + 1, y - 1);
        dfs(mine_map, x - 1, y);
        dfs(mine_map, x + 1, y);
        dfs(mine_map, x - 1, y + 1);
        dfs(mine_map, x, y + 1);
        dfs(mine_map, x + 1, y + 1);
        break;
    case 1:
        mine_map[x][y] = 11;
        break;
    case 2:
        mine_map[x][y] = 12;
        break;
    case 3:
        mine_map[x][y] = 13;
        break;
    case 4:
        mine_map[x][y] = 14;
        break;
    case 5:
        mine_map[x][y] = 15;
        break;
    case 6:
        mine_map[x][y] = 16;
        break;
    case 7:
        mine_map[x][y] = 17;
        break;
    case 8:
        mine_map[x][y] = 18;
        break;
    }
}

std::vector<int> game_state(std::vector<std::vector<int>>& mine_map) {
    //The first value of the vector can be either 1 or 0, if 1 a mine has been clicked on
    //The second value is the number of unrevealed tiles with no mines left, when it reaches 0 the win condition has been achieved
    //There is probbly a much better way to check for win conditiion but I went with this at the time.
    std::vector<int> con = { 0, 0 };
    for (int i = 0; i < mine_map.size(); i++) {
        for (int j = 0; j < mine_map[0].size(); j++)
        {
            if (mine_map[i][j] == 0) {
                con[1]++;
            }
            else if (mine_map[i][j] == 20) {
                con[0] = 1;
            }
        }
    }

    return con;

}

std::vector<std::vector<int>> init_map(int width, int height, int mine_num) {
    std::srand(std::time(0));
    std::vector<std::vector<int>> mine_map(width, std::vector<int>(height, 0));

   
    int num = 0;
    while (num < mine_num) {
        int x = rand() % width;
        int y = rand() % height;
        if (mine_map[x][y] != 1) {
            mine_map[x][y] = 1;
            num++;
        }
    }
    return mine_map;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 2500, 2000 }), "Minesweeper", sf::Style::Default);


    //generate Title and Menu and Other UI Items

    //Probably the worst code to ever be written in Visual Studio
    //But I dont know any alternatives :/
    
    sf::Font font("ByteBounce.ttf");
    sf::Text title(font);
    sf::Text credits(font);
    sf::Text start(font);
    sf::Text difficulty(font);
    sf::Text quit(font);
    sf::Text restart(font);
    sf::Text message(font);
    sf::Text easy(font);
    sf::Text medium(font);
    sf::Text hard(font);
    sf::Text timer_text(font);

    title.setString("Minesweeper");
    title.setCharacterSize(100);
    title.setPosition({ 50, 50 });
    credits.setString("By Alan Xu");
    credits.setCharacterSize(50);
    credits.setPosition({ 50, 175 });


    start.setString("Start");
    start.setCharacterSize(75);
    start.setPosition({100, 300});
    difficulty.setString("Difficulty");
    difficulty.setCharacterSize(75);
    difficulty.setPosition({100, 400});
    quit.setString("Quit");
    quit.setCharacterSize(75);
    quit.setPosition({100, 500});

    easy.setString("Easy");
    easy.setCharacterSize(75);
    easy.setPosition({ 100, 300 });
    medium.setString("Medium");
    medium.setCharacterSize(75);
    medium.setPosition({ 100, 400 });
    hard.setString("Hard");
    hard.setCharacterSize(75);
    hard.setPosition({ 100, 500 });

    restart.setString("Restart");
    restart.setCharacterSize(50);
    restart.setPosition({980, 0});
    restart.setFillColor(sf::Color(0, 0, 0));

    message.setCharacterSize(150);
    message.setPosition({ 50, 1800 });

    timer_text.setString("Timer: 0");
    timer_text.setCharacterSize(75);
    timer_text.setPosition({ 1500,0 });

    //The triangle in the menu
    sf::CircleShape arrow(25, 3);
    arrow.setPosition({ 50, 380 });
    arrow.rotate(sf::degrees(210));

    //The restart button outline
    sf::RectangleShape button({150, 75});
    button.setFillColor(sf::Color(192, 192, 192));
    button.setPosition({975, 0});
    
    std::vector<sf::Text> menu_options = {start, difficulty, quit};
    std::vector<sf::Text> difficulty_options = { easy, medium, hard };
    

    int menu_index = 0;

    
    
    //Generate Game Parameters
    //A lot of parameters are to determine what part of the game to display
    //Not sure how else to do it



    GridMap map;
    int height = 10;
    int width = 10;
    int max_height = 15;
    int max_width = 20;
    int mine_num = 15;
    bool lose_con = false;
    bool win_con = true;
    bool game_on = false;
    bool menu_on = true;
    bool difficulty_on = false;
    int transform_x = 100;
    int transform_y = 100;
    int timer = 0;
    
    std::cout << "Loading Minemap..." << std::endl;


    map.load("MinesweeperTextures.png", width, height, 100);
    map.setPosition({(float)transform_x, (float)transform_y});
    std::srand(std::time(0));

    
    //Looking at this, Im pretty sure init_map is unnecessary

    std::vector<std::vector<int>> mine_map = init_map(max_width, max_height, mine_num);
    map.reset(mine_map, width, height, mine_num, max_width, max_height);
    



    std::cout << "Loading Minemap successful " <<std::endl;

    /*
    Minesweeper Map key:
    Unrevealed + No Mine: 0
    Unrevealed + Mine: 1
    Flagged + No Mine: 2
    Flagged + Mine: 3
    Revealed + No Mine: 10
    Revealed + No Mine and Has Mine in vicnity: 11 - 18 based on number of mines in vicinity
    Revealed + Mine: 20

    */


    //For handling input, set default to false so that the application respond on the release of mouse button
    bool isPressedLeft = false;
    bool isPressedRight = false;
    bool isPressedKeyUp = false;
    bool isPressedKeyDown = false;
    bool isPressedKeyEnter = false;


    

    window.clear();
    window.draw(title);
    window.draw(credits);


    menu_options[menu_index].setStyle(sf::Text::Bold | sf::Text::Underlined);
    for (sf::Text item : menu_options) {
        window.draw(item);
    }
    window.draw(arrow);
    window.display();

    std::cout << "Menu Loading Successful" << std::endl;

    //Setting timer variables
    auto time_start = steady_clock::now();
    auto now = steady_clock::now();
    auto time_elapsed = duration_cast<std::chrono::seconds>(now - time_start).count();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        
        

        //Control for Menu
        //There is no tick speed cap in the game, so all the controls are to be executed on the cycle after release
        //I can't find a KeyRelease function on the current version so this is how to get around it

        if (window.hasFocus() and !game_on) {
        
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
                isPressedKeyUp = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
                isPressedKeyDown = true;
            }
            else {
                if (isPressedKeyUp) {
                    
                    if (menu_on) {
                        menu_options[menu_index].setStyle(sf::Text::Regular);
                    }
                    else if (difficulty_on) {
                        difficulty_options[menu_index].setStyle(sf::Text::Regular);
                    }
                    
                    menu_index -= 1;
                    menu_index =  (menu_index % 3 + 3) % 3;
                    
                    arrow.setPosition({ 50, 380 + 100 * (float)menu_index });
                    window.clear();
                    window.draw(title);
                    window.draw(credits);
                    if (menu_on) {
                        menu_options[menu_index].setStyle(sf::Text::Bold | sf::Text::Underlined);
                        for (sf::Text item : menu_options) {
                            window.draw(item);
                        }
                    }
                    else if (difficulty_on) {
                        difficulty_options[menu_index].setStyle(sf::Text::Bold | sf::Text::Underlined);
                        for (sf::Text item : difficulty_options) {
                            window.draw(item);
                        }
                    }
                    
                    window.draw(arrow);
                    window.display();
                    isPressedKeyUp = false;
                }
                else if (isPressedKeyDown) {
                    if (menu_on) {
                        menu_options[menu_index].setStyle(sf::Text::Regular);
                    }
                    else if (difficulty_on) {
                        difficulty_options[menu_index].setStyle(sf::Text::Regular);
                    }
                    menu_index += 1;
                    menu_index = (menu_index % 3 + 3) % 3;

                    arrow.setPosition({ 50, 380 + 100 * (float)menu_index });
                    window.clear();
                    window.draw(title);
                    window.draw(credits);
                    if (menu_on) {
                        menu_options[menu_index].setStyle(sf::Text::Bold | sf::Text::Underlined);
                        for (sf::Text item : menu_options) {
                            window.draw(item);
                        }
                    }
                    else if (difficulty_on) {
                        difficulty_options[menu_index].setStyle(sf::Text::Bold | sf::Text::Underlined);
                        for (sf::Text item : difficulty_options) {
                            window.draw(item);
                        }
                    }
                    window.draw(arrow);
                    window.display();
                    isPressedKeyDown = false;    
                }
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
                isPressedKeyEnter = true;
            }
            else if (isPressedKeyEnter) {
                if (menu_on) {
                    switch (menu_index) {
                    case 0:

                        //Game Start Here
                        game_on = true;
                        time_start = steady_clock::now();
                        window.clear();
                        window.draw(button);
                        window.draw(restart);
                        window.draw(timer_text);
                        window.draw(map);
                        window.display();
                        
                        break;
                    case 1:
                        std::cout << "Changing Difficulty" << std::endl;
                        menu_on = false;
                        difficulty_on = true;
                        window.clear();
                        window.draw(title);
                        window.draw(credits);
                        difficulty_options[menu_index].setStyle(sf::Text::Bold | sf::Text::Underlined);
                        for (sf::Text item : difficulty_options) {
                            window.draw(item);
                        }
                        window.draw(arrow);
                        window.display();
                        break;

                    case 2:
                        window.close();
                    }
                }
                else if (difficulty_on) {
                    std::cout << "Difficulty On!" << std::endl;
                    switch (menu_index) {
                    case 0:
                        height = 7;
                        width = 8;
                        mine_num = 7;
                        map.load("MinesweeperTextures.png", width, height, 100);
                        map.reset(mine_map, width, height, mine_num, max_width, max_height);
                        map.update(mine_map, width, height);
                        menu_on = true;
                        difficulty_on = false;
                        window.clear();
                        window.draw(title);
                        window.draw(credits);
                        menu_options[menu_index].setStyle(sf::Text::Bold | sf::Text::Underlined);
                        for (sf::Text item : menu_options) {
                            window.draw(item);
                        }
                        window.draw(arrow);
                        window.display();
                        break;
                    case 1:
                        height = 10;
                        width = 10;
                        mine_num = 15;
                        map.load("MinesweeperTextures.png", width, height, 100);
                        map.reset(mine_map, width, height, mine_num, max_width, max_height);
                        map.update(mine_map, width, height);
                        menu_on = true;
                        difficulty_on = false;
                        window.clear();
                        window.draw(title);
                        window.draw(credits);
                        menu_options[menu_index].setStyle(sf::Text::Bold | sf::Text::Underlined);
                        for (sf::Text item : menu_options) {
                            window.draw(item);
                        }
                        window.draw(arrow);
                        window.display();
                        break;
                    case 2:
                        height = 15;
                        width = 20;
                        mine_num = 67;
                        map.load("MinesweeperTextures.png", width, height, 100);
                        map.reset(mine_map, width, height, mine_num, max_width, max_height);
                        map.update(mine_map, width, height);
                        menu_on = true;
                        difficulty_on = false;
                        window.clear();
                        window.draw(title);
                        window.draw(credits);
                        menu_options[menu_index].setStyle(sf::Text::Bold | sf::Text::Underlined);
                        for (sf::Text item : menu_options) {
                            window.draw(item);
                        }
                        window.draw(arrow);
                        window.display();
                        break;
                    }

                }
                isPressedKeyEnter = false;
            }


            

        }

        //Click behaviour while in game
        if (window.hasFocus() and !lose_con and win_con and game_on) {

            //Progress Timer
            now = steady_clock::now();
            time_elapsed = duration_cast<std::chrono::seconds>(now - time_start).count();
            if (timer != time_elapsed and timer < 999) {
                timer = time_elapsed;
                std::string a = std::to_string(timer);

                timer_text.setString("Timer: " + a);
                window.clear();
                window.draw(button);
                window.draw(restart);
                window.draw(map);
                window.draw(timer_text);
                window.display();
                
            }
            
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                isPressedLeft = true;
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
                isPressedRight = true;

            }
            else {
                if (isPressedLeft) {
                    sf::Vector2i local_position = sf::Mouse::getPosition(window);
                    int tile_x = (local_position.x - transform_x) / 100;
                    int tile_y = (local_position.y - transform_y) / 100;
                    if (local_position.x > 975 and local_position.x < 1125 and local_position.y > 0 and local_position.y < 50) {

                        map.reset(mine_map, width, height, mine_num, max_width, max_height);
                        map.update(mine_map, width, height);
                        for (int j = 0; j < height; j++) {
                            for (int i = 0; i < width; i++) {
                                std::cout << mine_map[i][j];
                            }
                            std::cout << std::endl;
                        }
                        lose_con = false;
                        win_con = true;
                        timer = 0;
                        time_start = steady_clock::now();
                        timer_text.setString("Timer: 0");
                        window.clear();
                        window.draw(button);
                        window.draw(restart);
                        window.draw(map);
                        window.draw(timer_text);
                        window.display();
                        
                    } else if (tile_x < width and tile_y < height and tile_x >= 0 and tile_y >= 0) {
                        switch (mine_map[tile_x][tile_y]) {
                        case 0:
                            dfs(mine_map, tile_x, tile_y);
                            break;
                        case 1:
                            mine_map[tile_x][tile_y] = 20;
                            break;
                        }

                        map.update(mine_map, width, height);

                        //Lose Condition check
                        std::vector<int> game_con = game_state(mine_map);
                        if (game_con[0] == 1) {
                            lose_con = true;
                            
                        }
                        else if (game_con[1] == 0) {
                            win_con = false;
                        }

                        
                        window.clear();
                        window.draw(button);
                        window.draw(restart);
                        window.draw(map);
                        window.draw(timer_text);
                        window.display();

                    }
                    
                    isPressedLeft = false;
                }
                else if (isPressedRight) {
                    sf::Vector2i local_position = sf::Mouse::getPosition(window);
                    int tile_x = (local_position.x - transform_x) / 100;
                    int tile_y = (local_position.y - transform_y) / 100;
                    if (tile_x < width and tile_y < height) {
                        switch (mine_map[tile_x][tile_y]) {
                        case 0:
                            mine_map[tile_x][tile_y] = 2;
                            break;
                        case 1:
                            mine_map[tile_x][tile_y] = 3;
                            break;
                        case 2:
                            mine_map[tile_x][tile_y] = 0;
                            break;
                        case 3:
                            mine_map[tile_x][tile_y] = 1;
                            break;
                        }

                        map.update(mine_map, width, height);
                        window.clear();
                        window.draw(button);
                        window.draw(restart);
                        window.draw(map);
                        window.draw(timer_text);
                        window.display();
                    }
                    
                    isPressedRight = false;
                }
            }
        }
        //Displaying message when gameplay ends
        //I noticed that the restart button logic is repeated. I am too lazy to change it
        if (window.hasFocus() and (lose_con or !win_con)) {
            if (lose_con) {
                message.setString("You Lost! Better Luck Next Time");
                window.clear();
                window.draw(button);
                window.draw(restart);
                window.draw(map);
                window.draw(timer_text);
                window.draw(message);
                window.display();
            }
            else if (!win_con) {
                message.setString("You Win! Congrats!");
                window.clear();
                window.draw(button);
                window.draw(restart);
                window.draw(map);
                window.draw(message);
                window.draw(timer_text);
                window.display();
            }
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                isPressedLeft = true;
            }
            else if (isPressedLeft) {
                sf::Vector2i local_position = sf::Mouse::getPosition(window);
                if (local_position.x > 975 and local_position.x < 1125 and local_position.y > 0 and local_position.y < 50) {

                    map.reset(mine_map, width, height, mine_num, max_width, max_height);
                    map.update(mine_map, width, height);
                    lose_con = false;
                    win_con = true;
                    timer = 0;
                    time_start = steady_clock::now();
                    timer_text.setString("Timer: 0");
                    window.clear();
                    window.draw(button);
                    window.draw(restart);
                    window.draw(map);
                    window.draw(timer_text);
                    window.display();
                    
                }
            }
        }
    }
}

