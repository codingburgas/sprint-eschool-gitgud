//#include "app.h"
//#include "raylib.h"
//#include <string>
//#include <iostream>
//int ENGLISH() {
//    // Initialize the window
//    const int screenWidth = 800;
//    const int screenHeight = 450;
//    InitWindow(screenWidth, screenHeight, "Raylib User Input with std::string");
//
//    // Variables for user input
//    std::string inputText;
//    bool textInputActive = true; // Flag to indicate if text input is active
//
//    // Set the text position
//    int textX = 50;
//    int textY = screenHeight / 2 - 20;
//
//    // Enable text input mode
//    SetTargetFPS(60); // Set the FPS to 60
//
//    // Main game loop
//    while (!WindowShouldClose()) {
//        // Check for user input
//        if (textInputActive) {
//            int key = GetCharPressed();
//            while (key > 0) {
//                // Only allow printable characters
//                if ((key >= 32) && (key <= 125)) {
//                    inputText += static_cast<char>(key); // Append the character to the string
//                }
//                key = GetCharPressed(); // Get the next character
//            }
//
//            // Handle backspace
//            if (IsKeyPressed(KEY_BACKSPACE) && !inputText.empty()) {
//                inputText.pop_back(); // Remove the last character
//            }
//        }
//
//        // Toggle text input (for demonstration purposes)
//        if (IsKeyPressed(KEY_ENTER)) {
//            textInputActive = !textInputActive; // Toggle text input on/off
//        }
//
//        // Begin drawing
//        BeginDrawing();
//
//        // Clear the background
//        ClearBackground(RAYWHITE);
//
//        // Draw the user input text
//        DrawText("Enter text:", textX, textY - 30, 20, DARKGRAY);
//        DrawText(inputText.c_str(), textX, textY, 20, BLACK); // Use .c_str() to convert std::string to C-style string
//
//        // Draw instructions
//        DrawText("Press BACKSPACE to delete characters", textX, textY + 50, 20, GRAY);
//        DrawText("Press ENTER to toggle text input", textX, textY + 80, 20, GRAY);
//
//        // End drawing
//        EndDrawing();
//    }
//
//    // Close the window and unload resources
//    CloseWindow();
//
//    return 0;
//}