#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <termios.h>
#include <unistd.h>

using namespace std;

// Function to enable/disable terminal raw mode for character-by-character input
void setRawMode(bool enable) {
    static struct termios oldt, newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

// Trie Node definition
struct Trie {
    map<char, Trie*> children;
    vector<pair<string, int>> products;
    bool isEnd = false;
};

// Helper function to convert character to lowercase
char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

// Insert product into trie (case-insensitive)
void insertProduct(Trie* root, const string& product, int weight) {
    Trie* node = root;
    for (char c : product) {
        char lowerC = toLowerCase(c);
        if (!node->children[lowerC])
            node->children[lowerC] = new Trie();
        node = node->children[lowerC];
        node->products.push_back({product, weight});
    }
    node->isEnd = true;
}

// Function to search products by prefix (case-insensitive)
vector<pair<string, int>> searchProducts(Trie* root, const string& prefix) {
    Trie* node = root;
    for (char c : prefix) {
        char lowerC = toLowerCase(c);
        if (!node->children[lowerC])
            return {};
        node = node->children[lowerC];
    }
    
    vector<pair<string, int>> result = node->products;
    sort(result.begin(), result.end(), 
         [](const pair<string,int>& a, const pair<string,int>& b) {
             return a.second > b.second;
         });
    return result;
}

int main() {
    Trie* root = new Trie();
    
    
    insertProduct(root, "Amul Fresh Cream", 435);
    insertProduct(root, "Amul Masti Dahi", 430);
    insertProduct(root, "Amul Kool Flavoured Milk", 425);
    insertProduct(root, "Amul Ice Cream", 420);
    insertProduct(root, "Mother Dairy Ice Cream", 415);
    insertProduct(root, "Kwality Walls Ice Cream", 410);
    insertProduct(root, "Havmor Ice Cream", 405);
    insertProduct(root, "Vadilal Ice Cream", 400);
    insertProduct(root, "Britannia Rusk", 395);
    insertProduct(root, "Britannia Cake", 390);
    insertProduct(root, "Britannia Croissant", 385);
    insertProduct(root, "Britannia Winkin Cow Milkshake", 380);
    insertProduct(root, "Modern Multigrain Bread", 375);
    insertProduct(root, "English Oven Brown Bread", 370);
    insertProduct(root, "Harvest Gold Bread", 365);
    insertProduct(root, "Britannia Milk Bikis", 360);
    insertProduct(root, "Amul Gold Milk", 355);
    insertProduct(root, "Amul Taaza Milk", 350);
    insertProduct(root, "Amul Dahi Cup", 345);
    insertProduct(root, "Epigamia Greek Yogurt", 340);
    insertProduct(root, "Danone Yogurt", 335);
    insertProduct(root, "Nestle Yogurt", 330);
    insertProduct(root, "Mother Dairy Butter", 325);
    insertProduct(root, "Nandini Milk", 320);
    insertProduct(root, "Heritage Paneer", 315);
    insertProduct(root, "Govardhan Paneer", 310);
    insertProduct(root, "Amul Malai Paneer", 305);
    insertProduct(root, "Mother Dairy Ghee", 300);
    insertProduct(root, "Amul Pure Ghee", 295);
    insertProduct(root, "Nandini Butter", 290);
    insertProduct(root, "Britannia Cheese Spread", 285);
    insertProduct(root, "Amul Cheese Slice", 280);
    insertProduct(root, "Mother Dairy Lassi", 275);
    insertProduct(root, "Amul Buttermilk", 270);
    insertProduct(root, "Mother Dairy Buttermilk", 265);
    insertProduct(root, "Amul Mithai Mate", 260);
    insertProduct(root, "Nestle Everyday Dairy Whitener", 255);
    insertProduct(root, "Amulya Dairy Whitener", 250);
    insertProduct(root, "Britannia Digestive Biscuits", 245);
    insertProduct(root, "Britannia Marie Gold", 240);
    insertProduct(root, "Britannia Good Day Cashew", 235);
    insertProduct(root, "Britannia Treat Cookies", 230);
    insertProduct(root, "Oreo Biscuits", 400);
    insertProduct(root, "Hide & Seek Cookies", 425);
    insertProduct(root, "Little Debbie Swiss Roll", 410);
    insertProduct(root, "Sunfeast Dark Fantasy Choco Fills", 395);
    
   
    insertProduct(root, "Pillsbury Chakki Atta", 430);
    insertProduct(root, "Annapurna Atta", 425);
    insertProduct(root, "Nature Fresh Sampoorna Atta", 420);
    insertProduct(root, "Fortune Soya Oil", 415);
    insertProduct(root, "Dhara Refined Oil", 410);
    insertProduct(root, "Gemini Sunflower Oil", 405);
    insertProduct(root, "Sundrop Heart Oil", 400);
    insertProduct(root, "Emami Healthy & Tasty Oil", 395);
    insertProduct(root, "Tata Sampann Toor Dal", 390);
    insertProduct(root, "Tata Sampann Moong Dal", 385);
    insertProduct(root, "Tata Sampann Chana Dal", 380);
    insertProduct(root, "Fortune Sona Masoori Rice", 375);
    insertProduct(root, "Kohinoor Basmati Rice", 370);
    insertProduct(root, "India Gate Feast Rozzana Rice", 365);
    insertProduct(root, "Lal Qilla Basmati Rice", 360);
    insertProduct(root, "24 Mantra Organic Rice", 355);
    insertProduct(root, "Daawat Rozana Super Rice", 350);
    insertProduct(root, "Everest Kitchen King Masala", 345);
    insertProduct(root, "MDH Chana Masala", 340);
    insertProduct(root, "MDH Pav Bhaji Masala", 335);
    insertProduct(root, "Catch Black Pepper Powder", 330);
    insertProduct(root, "Everest Turmeric Powder", 325);
    insertProduct(root, "Patanjali Hing", 320);
    insertProduct(root, "Catch Mustard Seeds", 315);
    insertProduct(root, "24 Mantra Organic Tur Dal", 310);
    insertProduct(root, "Organic Tattva Moong Dal", 305);
    insertProduct(root, "Organic India Quinoa", 300);
    insertProduct(root, "Tata Sampann Besan", 295);
    insertProduct(root, "Aashirvaad Suji Rava", 290);
    insertProduct(root, "Madhur Sugar Cubes", 285);
    insertProduct(root, "Dhampur Brown Sugar", 280);
    insertProduct(root, "Tata Rock Salt", 275);
    insertProduct(root, "Catch Black Salt", 270);
    insertProduct(root, "Patanjali Himalayan Pink Salt", 265);
    insertProduct(root, "24 Mantra Organic Jaggery Powder", 260);
    insertProduct(root, "Patanjali Cow Ghee", 255);
    insertProduct(root, "Saffola Active Oil", 250);
    insertProduct(root, "Fortune Sunlite Refined Oil", 245);
    insertProduct(root, "Emami Mustard Oil", 240);
    insertProduct(root, "Dhara Kachi Ghani Mustard Oil", 235);
    insertProduct(root, "Fortune Rice Bran Oil", 230);
    insertProduct(root, "Sundrop Corn Oil", 225);
    insertProduct(root, "24 Mantra Organic Wheat Flour", 220);
    insertProduct(root, "Annapurna Whole Wheat Atta", 215);
    insertProduct(root, "Nature Fresh Whole Wheat Atta", 210);
    insertProduct(root, "Pillsbury Whole Wheat Atta", 205);
    insertProduct(root, "Tata Sampann Moong Dal Chilka", 200);
    

    insertProduct(root, "Mountain Dew", 365);
    insertProduct(root, "Thumbs Up", 360);
    insertProduct(root, "Limca", 355);
    insertProduct(root, "7UP", 350);
    insertProduct(root, "Sting Energy Drink", 345);
    insertProduct(root, "Monster Energy Drink", 340);
    insertProduct(root, "Minute Maid Pulpy Orange", 335);
    insertProduct(root, "Slice Mango Drink", 330);
    insertProduct(root, "Maaza", 325);
    insertProduct(root, "Mother Dairy Lassi", 315);
    insertProduct(root, "Nandini Curd", 310);
    insertProduct(root, "Epigamia Greek Yogurt", 305);
    insertProduct(root, "Nestle Milkmaid", 300);
    insertProduct(root, "Britannia Bourbon Biscuits", 290);
    insertProduct(root, "Oreo Chocolate Cream", 285);
    insertProduct(root, "Hide & Seek Cookies", 280);
    insertProduct(root, "Unibic Choco Chip Cookies", 275);
    insertProduct(root, "Marie Gold Biscuits", 270);
    insertProduct(root, "Good Day Cashew Cookies", 265);
    insertProduct(root, "Parle Monaco Biscuits", 260);
    insertProduct(root, "KrackJack Biscuits", 255);
    insertProduct(root, "50-50 Biscuits", 250);
    insertProduct(root, "Little Hearts", 245);
    insertProduct(root, "Milk Bikis", 240);
    insertProduct(root, "Jim Jam Biscuits", 235);
    insertProduct(root, "Sunfeast Bounce Cream Biscuits", 230);
    insertProduct(root, "Dark Fantasy Choco Fills", 225);
    insertProduct(root, "Bourbon Delight Biscuits", 220);
    insertProduct(root, "Maggi Masala Noodles 70g", 215);
    insertProduct(root, "Yippee Magic Masala", 210);
    insertProduct(root, "Top Ramen Curry Noodles", 205);
    insertProduct(root, "Knorr Soupy Noodles", 200);
    insertProduct(root, "Cup Noodles Veggie Delight", 195);
    insertProduct(root, "MTR Upma Ready Mix", 190);
    insertProduct(root, "MTR Dosa Batter", 185);
    insertProduct(root, "Haldiram's Ready to Eat Dal Makhani", 180);
    insertProduct(root, "Haldiram's Pav Bhaji Ready Meal", 175);
    insertProduct(root, "Haldiram's Rasgulla Tin", 170);
    insertProduct(root, "Bikano Gulab Jamun Tin", 165);
    insertProduct(root, "Haldiram's Soan Papdi", 160);
    insertProduct(root, "Bikaji Kaju Katli", 155);
    insertProduct(root, "Britannia Fruit Cake", 150);
    insertProduct(root, "Britannia Rusk", 145);
    insertProduct(root, "Tata Tea Premium", 140);
    insertProduct(root, "Tata Tea Agni", 135);
    insertProduct(root, "Tetley Green Tea", 130);
    insertProduct(root, "Lipton Green Tea", 125);
    insertProduct(root, "Nescafe Gold Coffee", 120);
    insertProduct(root, "Bru Gold Coffee", 115);
    insertProduct(root, "Starbucks Instant Coffee", 110);
    insertProduct(root, "Sleepy Owl Cold Brew", 105);
    insertProduct(root, "Blue Tokai Coffee", 100);
    insertProduct(root, "Amul Masti Buttermilk", 95);
    insertProduct(root, "Yakult Probiotic Drink", 90);
    insertProduct(root, "Frooti Mango Drink", 85);
    insertProduct(root, "Real Guava Juice", 80);
    insertProduct(root, "Real Pomegranate Juice", 75);
    insertProduct(root, "Paper Boat Jaljeera", 70);
    insertProduct(root, "Paper Boat Aam Panna", 65);
    insertProduct(root, "Bisleri Vedica Water", 60);
    insertProduct(root, "Himalayan Natural Water", 55);
    insertProduct(root, "Kinley Soda Bottle", 45);
    insertProduct(root, "Bisleri Soda 750ml", 40);
    
  
    insertProduct(root, "L'Oreal Paris Shampoo", 400);
    insertProduct(root, "Tresemme Keratin Smooth Shampoo", 395);
    insertProduct(root, "Pantene Pro-V Hair Fall Control", 390);
    insertProduct(root, "Clinic Plus Daily Care Shampoo", 385);
    insertProduct(root, "Dove Intense Repair Conditioner", 380);
    insertProduct(root, "Sunsilk Perfect Straight Conditioner", 375);
    insertProduct(root, "WOW Apple Cider Vinegar Shampoo", 370);
    insertProduct(root, "Himalaya Protein Hair Cream", 365);
    insertProduct(root, "Livon Hair Serum", 360);
    insertProduct(root, "Indulekha Bhringa Hair Oil", 355);
    insertProduct(root, "Bajaj Almond Drops Hair Oil", 350);
    insertProduct(root, "Navratna Cool Oil", 345);
    insertProduct(root, "Kesh King Ayurvedic Oil", 340);
    insertProduct(root, "Nyle Naturals Shampoo", 335);
    insertProduct(root, "Biotique Bio Green Apple Shampoo", 330);
    insertProduct(root, "Vaseline Healthy White Lotion", 325);
    insertProduct(root, "Nivea Body Milk", 320);
    insertProduct(root, "Dove Deep Moisture Body Wash", 315);
    insertProduct(root, "Pears Pure & Gentle Body Wash", 310);
    insertProduct(root, "Fiama Shower Gel", 305);
    insertProduct(root, "Dettol Skincare Handwash", 300);
    insertProduct(root, "Lifebuoy Total 10 Hand Wash", 295);
    insertProduct(root, "Savlon Deep Clean Hand Wash", 290);
    insertProduct(root, "Oral-B Pro Health Toothpaste", 285);
    insertProduct(root, "Colgate Max Fresh Gel", 280);
    insertProduct(root, "Close-Up Fire Freeze Gel", 275);
    insertProduct(root, "Dabur Red Toothpaste", 270);
    insertProduct(root, "Vicco Vajradanti Ayurvedic Paste", 265);
    insertProduct(root, "Sensodyne Rapid Relief", 260);
    insertProduct(root, "Listerine Mouthwash", 255);
    insertProduct(root, "Colgate Plax Mouthwash", 250);
    insertProduct(root, "Fair & Lovely Advanced Multivitamin", 245);
    insertProduct(root, "Ponds BB Cream", 240);
    insertProduct(root, "Lakme Perfect Radiance Cream", 235);
    insertProduct(root, "Nivea Men Dark Spot Reduction Cream", 230);
    insertProduct(root, "Olay Regenerist Micro-Sculpting Cream", 225);
    insertProduct(root, "Garnier Light Complete Serum Cream", 220);
    insertProduct(root, "Mamaearth Vitamin C Face Serum", 215);
    insertProduct(root, "WOW Skin Science Vitamin C Serum", 210);
    insertProduct(root, "The Man Company Beard Oil", 205);
    insertProduct(root, "Beardo Hair Wax", 200);
    insertProduct(root, "Ustraa Face Wash", 195);
    insertProduct(root, "Park Avenue After Shave Lotion", 190);
    insertProduct(root, "Gillette Foamy Shaving Cream", 185);
    insertProduct(root, "Nivea Men After Shave Balm", 180);
    insertProduct(root, "Gillette Mach3 Razor", 175);
    insertProduct(root, "Wilkinson Sword Blades", 170);
    insertProduct(root, "Old Spice Aftershave", 165);
    insertProduct(root, "Axe Body Spray", 160);
    insertProduct(root, "Nivea Deodorant Roll-On", 155);
    insertProduct(root, "Fogg Body Spray", 150);
    insertProduct(root, "Engage Perfume Spray", 145);
    insertProduct(root, "Yardley London Talc", 140);
    insertProduct(root, "Cinthol Deo Stick", 135);
    insertProduct(root, "Wild Stone Hydra Energy", 130);
    insertProduct(root, "Denver Hamilton Deo", 125);
    insertProduct(root, "Set Wet Gel", 120);
    insertProduct(root, "Gatsby Hair Styling Wax", 115);
    insertProduct(root, "Veet Hair Removal Cream", 110);
    insertProduct(root, "Gillette Venus Razor", 105);
    insertProduct(root, "Himalaya Lip Balm", 100);
    insertProduct(root, "Nivea Lip Care Original", 95);
    insertProduct(root, "Maybelline Baby Lips", 90);
    insertProduct(root, "Vaseline Lip Therapy", 85);
    
  
    insertProduct(root, "Dettol Antiseptic Liquid", 420);
    insertProduct(root, "Savlon Surface Disinfectant Spray", 415);
    insertProduct(root, "Colin Glass Cleaner", 410);
    insertProduct(root, "Cif Cream Cleaner", 405);
    insertProduct(root, "Ezee Liquid Detergent", 400);
    insertProduct(root, "Godrej Ezee Winterwear Wash", 395);
    insertProduct(root, "Comfort Fabric Conditioner", 390);
    insertProduct(root, "Downy Fabric Softener", 385);
    insertProduct(root, "Nirma Detergent Powder", 380);
    insertProduct(root, "Henko Stain Care", 375);
    insertProduct(root, "Ujala Fabric Whitener", 370);
    insertProduct(root, "Blue Bird Ultramarine Liquid", 365);
    insertProduct(root, "Dettol Disinfectant Surface Cleaner", 360);
    insertProduct(root, "Lifebuoy Germ Kill Spray", 355);
    insertProduct(root, "Odonil Room Spray Lavender", 350);
    insertProduct(root, "Air Wick Automatic Air Freshener", 345);
    insertProduct(root, "Ambi Pur Air Freshener", 340);
    insertProduct(root, "Baygon Insect Killer Spray", 335);
    insertProduct(root, "Hit Cockroach Killer", 330);
    insertProduct(root, "Hit Mosquito Spray", 325);
    insertProduct(root, "Mortein Mosquito Coil", 320);
    insertProduct(root, "Good Knight Fabric Roll-On", 315);
    insertProduct(root, "All Out Ultra Refill", 310);
    insertProduct(root, "Lizol Citrus Disinfectant", 305);
    insertProduct(root, "Domex Floor Cleaner Pine", 300);
    insertProduct(root, "Vim Liquid Lemon", 295);
    insertProduct(root, "Pril Lime Dishwash Liquid", 290);
    insertProduct(root, "Scotch-Brite Kitchen Wipe", 285);
    insertProduct(root, "Gala Broom", 280);
    insertProduct(root, "Gala Floor Mop Refill", 275);
    insertProduct(root, "Spotzero Spin Mop", 270);
    insertProduct(root, "3M Microfiber Cloth", 265);
    insertProduct(root, "Milton Spray Bottle", 260);
    insertProduct(root, "Pigeon Ironing Spray Starch", 255);
    insertProduct(root, "Dettol Laundry Sanitizer", 250);
    insertProduct(root, "Surf Excel Matic Front Load", 245);
    insertProduct(root, "Ariel Matic Top Load", 240);
    insertProduct(root, "Tide Pods Detergent", 235);
    insertProduct(root, "Persil Liquid Detergent", 230);
    insertProduct(root, "Finish Dishwasher Tablets", 225);
    insertProduct(root, "Vanish Stain Remover", 220);
    insertProduct(root, "Harpic Power Plus Toilet Cleaner", 215);
    insertProduct(root, "Domex Fresh Guard", 210);
    insertProduct(root, "Lizol Lavender Floor Cleaner", 205);
    insertProduct(root, "Odonil Block Jasmine", 200);
    insertProduct(root, "Air Wick Gel Freshener", 195);
    insertProduct(root, "Good Knight Gold Flash", 190);
    insertProduct(root, "Hit Rat Killer Cake", 185);
    insertProduct(root, "Baygon Ant & Roach Killer", 180);
    insertProduct(root, "Dettol Multi-Surface Cleaner", 175);
    insertProduct(root, "Savlon Antibacterial Soap", 170);
    insertProduct(root, "Godrej Aer Twist Air Freshener", 165);
    insertProduct(root, "Godrej Aer Pocket Bathroom Freshener", 160);
    insertProduct(root, "Lizol Floral Surface Cleaner", 155);
    insertProduct(root, "Mr Muscle Bathroom Cleaner", 150);
    
  
    insertProduct(root, "Amul Butter", 435);
    insertProduct(root, "Amul Cheese Slices", 430);
    insertProduct(root, "Britannia Cheese Cubes", 425);
    insertProduct(root, "Mother Dairy Ghee", 420);
    insertProduct(root, "Fortune Sunflower Oil", 415);
    insertProduct(root, "Dhara Mustard Oil", 410);
    insertProduct(root, "Everest Garam Masala", 405);
    insertProduct(root, "MDH Chana Masala", 400);
    insertProduct(root, "Catch Black Pepper Powder", 395);
    insertProduct(root, "Tata Salt", 390);
    insertProduct(root, "Aashirvaad Atta", 385);
    insertProduct(root, "Pillsbury Chakki Atta", 380);
    insertProduct(root, "India Gate Basmati Rice", 375);
    insertProduct(root, "Daawat Biryani Rice", 370);
    insertProduct(root, "Tata Sampann Toor Dal", 365);
    insertProduct(root, "Fortune Besan", 360);
    insertProduct(root, "MTR Rasam Powder", 355);
    insertProduct(root, "Priya Pickles Mango", 350);
    insertProduct(root, "Mother's Recipe Lime Pickle", 345);
    insertProduct(root, "Kraft Mayonnaise", 340);
    insertProduct(root, "FunFoods Burger Mayo", 335);
    insertProduct(root, "Del Monte Tomato Ketchup", 330);
    insertProduct(root, "Hershey's Chocolate Syrup", 325);
    insertProduct(root, "Mapro Strawberry Crush", 320);
    insertProduct(root, "Tang Orange Drink Mix", 315);
    insertProduct(root, "Complan Nutrition Drink", 310);
    insertProduct(root, "Horlicks Classic Malt", 305);
    insertProduct(root, "Bournvita Chocolate Drink", 300);
    insertProduct(root, "Boost Energy Drink", 295);
    insertProduct(root, "Bru Instant Coffee", 290);
    insertProduct(root, "Nescafe Classic Coffee", 285);
    insertProduct(root, "Tata Tea Gold", 280);
    insertProduct(root, "Red Label Tea", 275);
    insertProduct(root, "Lipton Green Tea", 270);
    insertProduct(root, "Twinings English Breakfast Tea", 265);
    insertProduct(root, "Paper Boat Jaljeera", 260);
    insertProduct(root, "Slice Mango Drink", 255);
    insertProduct(root, "Maaza Mango Drink", 250);
    insertProduct(root, "Frooti Mango Drink", 245);
    insertProduct(root, "Appy Fizz", 240);
    insertProduct(root, "Coca Cola", 235);
    insertProduct(root, "Pepsi", 230);
    insertProduct(root, "Sprite", 225);
    insertProduct(root, "Mirinda", 220);
    insertProduct(root, "7 Up", 215);
    insertProduct(root, "Bisleri Mineral Water", 210);
    insertProduct(root, "Aquafina Mineral Water", 205);
    insertProduct(root, "Kinley Soda", 200);
    insertProduct(root, "Real Cranberry Juice", 195);
    insertProduct(root, "Tropicana Orange Juice", 190);
    insertProduct(root, "Paper Boat Tender Coconut Water", 185);
    insertProduct(root, "Diet Coke", 390);
    
    
    insertProduct(root, "Apple", 500);
    insertProduct(root, "Banana", 495);
    insertProduct(root, "Orange", 490);
    insertProduct(root, "Mango", 485);
    insertProduct(root, "Grapes", 480);
    insertProduct(root, "Watermelon", 475);
    insertProduct(root, "Pineapple", 470);
    insertProduct(root, "Potato", 465);
    insertProduct(root, "Onion", 460);
    insertProduct(root, "Tomato", 455);
    insertProduct(root, "Carrot", 450);
    insertProduct(root, "Broccoli", 445);
    insertProduct(root, "Zucchini", 440);
    insertProduct(root, "Lettuce", 435);
    insertProduct(root, "Avocado", 430);
    insertProduct(root, "Cucumber", 425);
    insertProduct(root, "Spinach", 420);
    insertProduct(root, "Cabbage", 415);
    insertProduct(root, "Cauliflower", 410);
    insertProduct(root, "Beetroot", 405);
    insertProduct(root, "Pumpkin", 400);
    insertProduct(root, "Papaya", 395);
    insertProduct(root, "Strawberry", 390);
    insertProduct(root, "Blueberry", 385);
    insertProduct(root, "Pomegranate", 380);
    insertProduct(root, "Guava", 375);
    insertProduct(root, "Pear", 370);
    insertProduct(root, "Peach", 365);
    insertProduct(root, "Kiwi", 360);
    insertProduct(root, "Sweet Lime", 355);
    insertProduct(root, "Coconut", 350);
    insertProduct(root, "Green Peas", 345);
    insertProduct(root, "Corn", 340);
    insertProduct(root, "Radish", 335);
    insertProduct(root, "Capsicum", 330);
    insertProduct(root, "Bitter Gourd", 325);
    insertProduct(root, "Lady Finger", 320);
    insertProduct(root, "Drumstick", 315);
    insertProduct(root, "Coriander Leaves", 310);
    insertProduct(root, "Mint Leaves", 305);
    insertProduct(root, "Ginger", 300);
    insertProduct(root, "Garlic", 295);
    insertProduct(root, "Chili", 290);
    insertProduct(root, "Lemon", 285);
    insertProduct(root, "Celery", 280);
    insertProduct(root, "Mushroom", 275);
    insertProduct(root, "Raspberry", 270);
    insertProduct(root, "Blackberry", 265);
    insertProduct(root, "Apricot", 260);
    insertProduct(root, "Cherry", 255);
    insertProduct(root, "Plum", 250);
    insertProduct(root, "Lychee", 245);
    insertProduct(root, "Jackfruit", 240);
    insertProduct(root, "Sapota", 235);
    insertProduct(root, "Turnip", 230);
    insertProduct(root, "Brinjal", 225);
    insertProduct(root, "Cucumber English", 220);
    insertProduct(root, "Sweet Potato", 215);
    insertProduct(root, "Parsley", 210);
    insertProduct(root, "Basil Leaves", 205);
    insertProduct(root, "Tapioca", 200);
    
    
    insertProduct(root, "Pampers Diapers", 500);
    insertProduct(root, "Huggies Diapers", 495);
    insertProduct(root, "Mee Mee Baby Lotion", 490);
    insertProduct(root, "Johnson's Baby Shampoo", 485);
    insertProduct(root, "Nestle Cerelac", 480);
    insertProduct(root, "Similac Infant Formula", 475);
    insertProduct(root, "Chicco Baby Wipes", 470);
    insertProduct(root, "Johnson's Baby Powder", 465);
    insertProduct(root, "Johnson's Baby Oil", 460);
    insertProduct(root, "Johnson's Baby Cream", 455);
    insertProduct(root, "Himalaya Baby Lotion", 450);
    insertProduct(root, "Himalaya Baby Wash", 445);
    insertProduct(root, "Himalaya Baby Powder", 440);
    insertProduct(root, "Sebamed Baby Lotion", 435);
    insertProduct(root, "Sebamed Baby Wash", 430);
    insertProduct(root, "Sebamed Diaper Rash Cream", 425);
    insertProduct(root, "Mamaearth Moisturizing Lotion for Babies", 420);
    insertProduct(root, "Mamaearth Deep Nourishing Baby Wash", 415);
    insertProduct(root, "Mamaearth Baby Rash Cream", 410);
    insertProduct(root, "Baby Dove Rich Moisture Shampoo", 405);
    insertProduct(root, "Baby Dove Lotion", 400);
    insertProduct(root, "Baby Dove Soap Bar", 395);
    insertProduct(root, "Chicco No Tears Shampoo", 390);
    insertProduct(root, "Chicco Body Lotion", 385);
    insertProduct(root, "Chicco Massage Oil", 380);
    insertProduct(root, "Mee Mee Mild Baby Shampoo", 375);
    insertProduct(root, "Mee Mee Gentle Baby Wash", 370);
    insertProduct(root, "Mee Mee Feeding Bottle", 365);
    insertProduct(root, "Philips Avent Feeding Bottle", 360);
    insertProduct(root, "Philips Avent Breast Pump", 355);
    insertProduct(root, "LuvLap Baby Diapers", 350);
    insertProduct(root, "LuvLap Baby Stroller", 345);
    insertProduct(root, "LuvLap Feeding Bottle", 340);
    insertProduct(root, "Pigeon Baby Wipes", 335);
    insertProduct(root, "Pigeon Baby Shampoo", 330);
    insertProduct(root, "Pigeon Bottle Sterilizer", 325);
    insertProduct(root, "Farlin Baby Lotion", 320);
    insertProduct(root, "Farlin Baby Bottle", 315);
    insertProduct(root, "Sebamed Baby Cleansing Bar", 310);
    insertProduct(root, "Huggies Wipes Pure & Clean", 305);
    insertProduct(root, "Pampers Premium Care Pants", 300);
    insertProduct(root, "Pampers Active Baby Diapers", 295);
    insertProduct(root, "Nestle Lactogen Infant Formula", 290);
    insertProduct(root, "Enfamil A+ Infant Formula", 285);
    insertProduct(root, "Dexolac Infant Milk Powder", 280);
    insertProduct(root, "Farex Infant Formula", 275);
    insertProduct(root, "Nestle NAN PRO 1 Infant Formula", 270);
    insertProduct(root, "Nestle NAN PRO 2 Follow-up Formula", 265);
    insertProduct(root, "Gerber Rice Cereal", 260);
    insertProduct(root, "Gerber Fruit Puree", 255);
    insertProduct(root, "Heinz Baby Cereal", 250);
    insertProduct(root, "Earth Mama Diaper Balm", 245);
    insertProduct(root, "The Moms Co. Natural Baby Lotion", 240);
    insertProduct(root, "The Moms Co. Natural Baby Shampoo", 235);
    insertProduct(root, "The Moms Co. Diaper Rash Cream", 230);
    insertProduct(root, "Mother Sparsh Water-Based Wipes", 225);
    insertProduct(root, "Mother Sparsh Baby Lotion", 220);
    insertProduct(root, "Mother Sparsh Plant Powered Wash", 215);
    insertProduct(root, "Himalaya Baby Diapers", 210);
    insertProduct(root, "Mamaearth Diaper Rash Cream", 205);
    insertProduct(root, "Chicco Baby Feeding Bottle", 200);
    insertProduct(root, "Nestle Lactogen 1 Starter Formula", 195);
    insertProduct(root, "Nestle Cerelac Wheat Apple Cereal", 190);
    insertProduct(root, "Gerber Banana Cereal", 185);
    insertProduct(root, "Dexolac Stage 2 Infant Milk Powder", 180);
    insertProduct(root, "Farex Gentle Infant Formula", 175);
    insertProduct(root, "Enfamil A+ Stage 2 Formula", 170);
    insertProduct(root, "Pampers Baby Dry Pants", 165);
    insertProduct(root, "Huggies Wonder Pants", 160);
    insertProduct(root, "LuvLap Diaper Pants", 155);
    insertProduct(root, "Mee Mee Soft Cleansing Wipes", 150);
    
    
    insertProduct(root, "McCain French Fries", 500);
    insertProduct(root, "McCain Veggie Nuggets", 495);
    insertProduct(root, "Godrej Yummiez Chicken Nuggets", 490);
    insertProduct(root, "ITC Master Chef Aloo Tikki", 485);
    insertProduct(root, "Prasuma Momos", 480);
    insertProduct(root, "MTR Pongal Mix", 475);
    insertProduct(root, "iD Fresh Idli Dosa Batter", 470);
    insertProduct(root, "ITC Master Chef Veg Burger Patty", 465);
    insertProduct(root, "McCain Smiles Potato Bites", 460);
    insertProduct(root, "McCain Chilli Garlic Potato Bites", 455);
    insertProduct(root, "Yummiez Chicken Sausages", 450);
    insertProduct(root, "Venky's Chicken Nuggets", 445);
    insertProduct(root, "Venky's Chicken Salami", 440);
    insertProduct(root, "Prasuma Chicken Momos", 435);
    insertProduct(root, "Wow! Momo Veg Momos", 430);
    insertProduct(root, "Wow! Momo Chicken Momos", 425);
    insertProduct(root, "iD Fresh Paratha", 420);
    insertProduct(root, "ITC Master Chef Malabar Paratha", 415);
    insertProduct(root, "Godrej Yummiez Chicken Popcorn", 410);
    insertProduct(root, "McCain Veggie Fingers", 405);
    insertProduct(root, "Sumeru Malabar Paratha", 400);
    insertProduct(root, "Sumeru Chicken Nuggets", 395);
    insertProduct(root, "MTR Upma Ready Mix", 390);
    insertProduct(root, "MTR Poha Ready Mix", 385);
    insertProduct(root, "Gits Dosa Mix", 380);
    insertProduct(root, "Gits Idli Mix", 375);
    insertProduct(root, "Gits Gulab Jamun Mix", 370);
    insertProduct(root, "iD Fresh Malabar Parotta", 365);
    insertProduct(root, "Tasty Bite Chana Masala Ready Meal", 360);
    insertProduct(root, "Tasty Bite Dal Makhani Ready Meal", 355);
    insertProduct(root, "Haldiram's Rajma Raseela Ready Meal", 350);
    insertProduct(root, "Haldiram's Paneer Butter Masala Ready Meal", 345);
    insertProduct(root, "Haldiram's Dal Tadka Ready Meal", 340);
    insertProduct(root, "MTR Rajma Masala Ready to Eat", 335);
    insertProduct(root, "MTR Paneer Butter Masala Ready to Eat", 330);
    insertProduct(root, "MTR Dal Fry Ready to Eat", 325);
    insertProduct(root, "Haldiram's Pav Bhaji Ready Meal", 320);
    insertProduct(root, "Haldiram's Veg Biryani Ready Meal", 315);
    insertProduct(root, "Tasty Bite Vegetable Biryani", 310);
    insertProduct(root, "ITC Kitchens of India Dal Bukhara", 305);
    insertProduct(root, "ITC Kitchens of India Paneer Darbari", 300);
    insertProduct(root, "Kitchens of India Rajma Masala", 295);
    insertProduct(root, "Haldiram's Poori Bhaji Combo", 290);
    insertProduct(root, "Prasuma Pork Momos", 285);
    insertProduct(root, "Sumeru Chicken Seekh Kebab", 280);
    insertProduct(root, "Yummiez Chicken Kebab", 275);
    insertProduct(root, "Venky's Chicken Kebab", 270);
    insertProduct(root, "Licious Chicken Seekh Kebab", 265);
    insertProduct(root, "Licious Mutton Galouti Kebab", 260);
    insertProduct(root, "Fresho Ready-to-Cook Veg Cutlet", 255);
    insertProduct(root, "Fresho Ready-to-Cook Paneer Tikka", 250);
    insertProduct(root, "iD Fresh Whole Wheat Chapati", 245);
    insertProduct(root, "Sumeru Veg Spring Rolls", 240);
    insertProduct(root, "Haldiram's Frozen Aloo Tikki", 235);
    insertProduct(root, "McCain Masala Fries", 230);
    insertProduct(root, "Godrej Yummiez Chicken Fingers", 225);
    insertProduct(root, "Prasuma Veg Momos", 220);
    insertProduct(root, "Wow! Momo Tandoori Chicken Momos", 215);
    insertProduct(root, "Wow! Momo Paneer Momos", 210);
    insertProduct(root, "MTR Lemon Rice Ready Mix", 205);
    insertProduct(root, "Gits Rava Idli Mix", 200);
    
   
    insertProduct(root, "24 Mantra Organic Toor Dal", 500);
    insertProduct(root, "Organic India Green Tea", 495);
    insertProduct(root, "Kapiva Aloe Vera Juice", 490);
    insertProduct(root, "Patanjali Giloy Juice", 485);
    insertProduct(root, "Saffola Active Oil", 480);
    insertProduct(root, "Himalaya Ashwagandha Tablets", 475);
    insertProduct(root, "Zandu Chyawanprash", 470);
    insertProduct(root, "Dabur Chyawanprash", 465);
    insertProduct(root, "Baidyanath Chyawanprash", 460);
    insertProduct(root, "Patanjali Chyawanprash", 455);
    insertProduct(root, "Organic India Tulsi Tea", 450);
    insertProduct(root, "Sri Sri Tattva Turmeric Tablets", 445);
    insertProduct(root, "Zandu Balm", 440);
    insertProduct(root, "Baidyanath Ashwagandha Churna", 435);
    insertProduct(root, "Dabur Honitus Syrup", 430);
    insertProduct(root, "Himalaya Septilin Syrup", 425);
    insertProduct(root, "Kapiva Amla Juice", 420);
    insertProduct(root, "Patanjali Amla Juice", 415);
    insertProduct(root, "Organic India Triphala Capsules", 410);
    insertProduct(root, "Zandu Pancharishta", 405);
    insertProduct(root, "Himalaya Liv.52 Syrup", 400);
    insertProduct(root, "Dabur Honey", 395);
    insertProduct(root, "Saffola Honey Active", 390);
    insertProduct(root, "24 Mantra Organic Brown Rice", 385);
    insertProduct(root, "Natureland Organics Moong Dal", 380);
    insertProduct(root, "Just Organik Chana Dal", 375);
    insertProduct(root, "Pro Nature Organic Masoor Dal", 370);
    insertProduct(root, "Saffola Fittify Green Coffee", 365);
    insertProduct(root, "Kapiva Wheatgrass Juice", 360);
    insertProduct(root, "Himalaya Koflet Lozenges", 355);
    insertProduct(root, "Zandu Pure Honey", 350);
    insertProduct(root, "Organic Tattva Whole Wheat Atta", 345);
    insertProduct(root, "Pro Nature Organic Sugar", 340);
    insertProduct(root, "Organic India Moringa Capsules", 335);
    insertProduct(root, "Kapiva Neem Juice", 330);
    insertProduct(root, "Baidyanath Triphala Churna", 325);
    insertProduct(root, "Patanjali Divya Medohar Vati", 320);
    insertProduct(root, "Himalaya Septilin Tablets", 315);
    insertProduct(root, "Zandu Kesari Jivan", 310);
    insertProduct(root, "Dabur Ashwagandha Tablets", 305);
    insertProduct(root, "Sri Sri Tattva Shatavari Tablets", 300);
    insertProduct(root, "Kapiva Giloy Tulsi Juice", 295);
    insertProduct(root, "Saffola Gold Cooking Oil", 290);
    insertProduct(root, "Pro Nature Organic Turmeric Powder", 285);
    insertProduct(root, "Organic India Psyllium Husk", 280);
    insertProduct(root, "Baidyanath Aloe Vera Juice", 275);
    insertProduct(root, "Zandu Ultra Power Balm", 270);
    insertProduct(root, "Himalaya Rumalaya Gel", 265);
    insertProduct(root, "Dabur Shilajit Gold Capsules", 260);
    insertProduct(root, "Patanjali Divya Arjun Kwath", 255);
    insertProduct(root, "Kapiva Apple Cider Vinegar", 250);
    insertProduct(root, "Saffola Aura Olive Oil", 245);
    insertProduct(root, "Organic India Ashwagandha Capsules", 240);
    insertProduct(root, "24 Mantra Organic Jaggery Powder", 235);
    insertProduct(root, "Pro Nature Organic Besan", 230);
    insertProduct(root, "Natureland Organics Brown Sugar", 225);
    insertProduct(root, "Organic Tattva Urad Dal", 220);
    insertProduct(root, "Kapiva Diabetic Care Juice", 215);
    insertProduct(root, "Himalaya Gokshura Tablets", 210);
    insertProduct(root, "Zandu Vigorex Capsules", 205);
    insertProduct(root, "Dabur Triphala Tablets", 200);
    
    
    insertProduct(root, "Pedigree Dog Food", 500);
    insertProduct(root, "Whiskas Cat Food", 495);
    insertProduct(root, "Drools Puppy Food", 490);
    insertProduct(root, "Royal Canin Adult Food", 485);
    insertProduct(root, "Supercoat Dog Food", 480);
    insertProduct(root, "Me-O Cat Food", 475);
    insertProduct(root, "Purepet Dog Food", 470);
    insertProduct(root, "Farmina N&D Grain Free Dog Food", 465);
    insertProduct(root, "Canine Creek Dog Food", 460);
    insertProduct(root, "Sheba Wet Cat Food", 455);
    insertProduct(root, "SmartHeart Dog Food", 450);
    insertProduct(root, "Acana Dog Food", 445);
    insertProduct(root, "Orijen Cat Food", 440);
    insertProduct(root, "Drools Cat Food", 435);
    insertProduct(root, "Whiskas Wet Cat Food", 430);
    insertProduct(root, "JerHigh Dog Treats", 425);
    insertProduct(root, "Choostix Dog Treats", 420);
    insertProduct(root, "Goodies Energy Treats", 415);
    insertProduct(root, "Royal Canin Kitten Food", 410);
    insertProduct(root, "Farmina N&D Cat Food", 405);
    insertProduct(root, "Kennel Kitchen Dog Food", 400);
    insertProduct(root, "Himalaya Healthy Pet Food", 395);
    insertProduct(root, "Drools Focus Starter Puppy Food", 390);
    insertProduct(root, "SmartHeart Cat Food", 385);
    insertProduct(root, "Temptations Cat Treats", 380);
    insertProduct(root, "Purepet Cat Food", 375);
    insertProduct(root, "Me-O Creamy Treats", 370);
    insertProduct(root, "Royal Canin Puppy Food", 365);
    insertProduct(root, "Farmina Puppy Starter Food", 360);
    insertProduct(root, "Pedigree Biscrok Treats", 355);
    insertProduct(root, "JerHigh Chicken Treats", 350);
    insertProduct(root, "Vitapol Bird Food", 345);
    insertProduct(root, "Petslife Bird Feed", 340);
    insertProduct(root, "Wiggles Dog Supplements", 335);
    insertProduct(root, "Trixie Dog Shampoo", 330);
    insertProduct(root, "Captain Zack Pet Shampoo", 325);
    insertProduct(root, "Himalaya Erina Shampoo", 320);
    insertProduct(root, "Petvit Multivitamin Tablets", 315);
    insertProduct(root, "Petkin Pet Wipes", 310);
    insertProduct(root, "Whiskas Kitten Food", 305);
    insertProduct(root, "Royal Canin Persian Cat Food", 300);
    insertProduct(root, "Tetra Bits Fish Food", 295);
    insertProduct(root, "Optimum Fish Food", 290);
    insertProduct(root, "Ocean Free Fish Food", 285);
    insertProduct(root, "Taiyo Fish Food", 280);
    insertProduct(root, "Vitapol Hamster Food", 275);
    insertProduct(root, "SmartHeart Rabbit Food", 270);
    insertProduct(root, "Vitapol Guinea Pig Food", 265);
    insertProduct(root, "TetraMin Flakes Fish Food", 260);
    insertProduct(root, "Tetra Color Bits", 255);
    insertProduct(root, "Whiskas Tuna Cat Food", 250);
    insertProduct(root, "Pedigree Meat & Rice", 245);
    insertProduct(root, "Drools Chicken & Egg", 240);
    insertProduct(root, "Supercoat Adult Chicken Food", 235);
    insertProduct(root, "Royal Canin Labrador Retriever Food", 230);
    insertProduct(root, "Farmina N&D Low Grain Food", 225);
    insertProduct(root, "Canine Creek Puppy Starter", 220);
    insertProduct(root, "Me-O Tuna Cat Food", 215);
    insertProduct(root, "Purepet Adult Dog Food", 210);
    insertProduct(root, "Himalaya Digyton Drops", 205);
    insertProduct(root, "Trixie Pet Comb", 200);
    
    // Dynamic search with live updates
    string prefix = "";
    char c;
    
    cout << "Start typing product name (press ESC or Ctrl+C to exit):\n";
    cout << "Search: " << flush;
    
    setRawMode(true);
    
    while (true) {
        c = getchar();
        
        // Exit on ESC (27) or Ctrl+C
        if (c == 27 || c == 3) {
            break;
        }
        
        // Handle backspace (127 or 8)
        if (c == 127 || c == 8) {
            if (!prefix.empty()) {
                prefix.pop_back();
                cout << "\b \b" << flush;
            }
        }
        // Handle newline/enter
        else if (c == '\n' || c == '\r') {
            continue;
        }
        // Handle printable characters
        else if (c >= 32 && c <= 126) {
            prefix += c;
            cout << c << flush;
        }
        else {
            continue;
        }
        
        // Clear previous results and show new ones
        cout << "\n\n";
        
        if (prefix.empty()) {
            cout << "Type to search...\n";
        } else {
            vector<pair<string,int>> matches = searchProducts(root, prefix);
            
            if(matches.empty()) {
                cout << "No products found starting with \"" << prefix << "\"\n";
            } else {
                cout << "Found " << matches.size() << " product(s):\n";
                // Show top 10 results
                int count = 0;
                for (const auto& p : matches) {
                    if (count >= 10) break;
                    cout << "  " << p.first << " (Weight: " << p.second << ")\n";
                    count++;
                }
                if (matches.size() > 10) {
                    cout << "  ... and " << (matches.size() - 10) << " more\n";
                }
            }
        }
        
        cout << "\nSearch: " << prefix << flush;
    }
    
    setRawMode(false);
    cout << "\n\nThank you for using the product search!\n";
    

    
    return 0;
}
