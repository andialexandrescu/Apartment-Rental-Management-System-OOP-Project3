#include <iostream>
#include <thread>
#include <limits>
#include <algorithm>
#include "Apartment.h"
#include "User.h"
#include "Reservation.h"
#include "SearchEngine.h"
#include "RoomLayout.h"
#include "ApartmentLayout.h"
#include "RoomBuilder.h"
#include "Post.h"
#include "ApartmentListingPost.h"
#include "VacationPackagePost.h"
#include "PackageType.h"

// couldn't think of a general scenario for project 3 so there's another section for developers, who are able to test the beta version of this application
int main() {
    // using setters to get rid of [unusedFunction] cppcheck error
    User test;
    test.setUsername("testing");

    Apartment Ap1("12rg3g0", "Benidorm, Spain", "Rental Unit", "Apartment Ideal to enjoy Playa de Benidorm, in the heart of Playa de Poniente. Views from the living room to the ocean and the Isle of Benidorm.", 4, 5, 136);
    Apartment Ap2("1wd27", "Santona, Spain", "Duplex", "Unique oceanfront location within a few meters from the beach. Very large terrace to enjoy.", 4, 6, 155);
    Apartment Ap3("323w", "Altea, Spain", "Villa", "Beautiful villa with a private pool and a hot tub in Altea’s prime location, on Don Cayo golf course and nestled away from highway noise. Ideal for big families or groups.", 4, 4, 120);
    Apartment Ap4("56sf7", "Florence, Italy", "Rental Unit", "Chez Geraldine is an apartment just outside the historical center. It’s predominantly a residential district, but the cathedral, Galleria dell'Accademia, and Piazza San Marco are a 15-minute walk away. Food stores, restaurants, and bars are close by.", 3, 5, 90);
    Apartment Ap5("9g65", "Dubrovnik, Croatia", "Rental Unit", "The apartment is perched on a small hill in Montovjerna, offering stunning views of the Adriatic Sea. Dubrovnik's Old Town is around a five-minute drive away, while the nearest beach, Bellevue, is around 300 metres away.", 4, 7, 180);
    Apartment Ap6("hdhsa", "Malaga, Spain", "Rental Unit", "Our vacation apartment with terrace and sea view is located on the beachfront, in the Huelin area. The seafront promenade and Plaza de Huelin are just 20 meters away.", 4, 7, 210);
    Apartment Ap7("dsaa53", "A Coruna, Spain", "Mansion", "La Casa de la Pradera is located in A Bana, A Coruna, Galicia. It is located 50 km from O Grove.", 4, 4, 115);
    Apartment Ap8("edas2sa", "Florence, Italy", "Entire Condo", "The apartment is located in a pedestrian area in the historic center of Florence, a stone's throw from the Duomo and Piazza della Signoria, and not far from the Ponte Vecchio and the Mercato di San Lorenzo.", 3, 4, 220);
    Apartment Ap9("adsw3aa", "Lecce, Italy", "Entire Suite", "Wooden Cabin situated just under 1 km away from Torre Rinalda and 9 km from Oaks.", 3, 4, 80);
    Apartment Ap10("sdgfas4", "Furore, Italy", "Duplex", "Romantic, quiet and sea view, this accommodation opens to the cozy area, consisting of a small living room with kitchenette from which you can access the panoramic terrace", 3, 4, 110);
    Apartment Ap11("sajgsd", "Lefkada, Greece", "Villa", "On the west coast of Lefkada, there are unlimited spectacles offered by all indoor and outdoor spaces, showcasing the sea and sunset on the horizon.", 2, 3, 145);
    Apartment Ap12("asfDSDG", "Ko Samui, Thailand", "Entire Condo", "Enjoy the panoramic sea and mountain views from the pool, terrace and lush garden. The villa is located on a small hilltop in Maenam village, a locals-only spot with a bustling night market and long sandy beach.", 5, 8, 120);
    Apartment Ap13("fsafAS", "Kas, Turkey", "Villa", "This rental holiday villa is located in Kördere area of Kalkan. It is a holiday villa with sea view and with unseen pool area. The city center is 3 km away.", 5, 12, 260);
    Apartment Ap14("sajgsd", "Lefkada, Greece", "Villa", "On the west coast of Lefkada, there are unlimited spectacles offered by all indoor and outdoor spaces, showcasing the sea and sunset on the horizon.", 2, 3, 145);
    Apartment Ap15("gsdAAS", "Jezierze, Poland", "Houseboat", "The Moors, or a cottage on the water, is a unique place where you can relax and connect with nature in a special way.", 1, 3, 75);
    Apartment Ap16("adsFAD", "Warsaw, Poland", "Rental Unit", "This apartment can be found in the modern city center, near Grzybowski Square and Saski Garden. A supermarket is located in the same building, and the Hala Mirowska food market is nearby, along with restaurants, cafes, and 2 modern art galleries.", 4, 5, 210);
    Apartment Ap17("fdjhg9", "Rabka-Zdroj, Poland", "Cottage", "Comfortable year-round cottages, located on a hill with a beautiful view of the forest. The perfect place to relax away from the hustle and bustle.", 3, 4, 125);

    query += Ap1; query += Ap2; query += Ap3; query += Ap4; query += Ap5; query += Ap6; query += Ap7; query += Ap8; query += Ap9; query += Ap10; query += Ap11; query += Ap12; query += Ap13; query += Ap14; query += Ap15; query += Ap16; query += Ap17;

    Post<std::string, 25> welcome_post("Andra Alexandrescu", "Welcome message!");
    Post<std::string, 25> goodbye_post;
    Post<int, 10> quality_score;
    Post<float, 10> rating;
    Post<Apartment, 1> apt_listing1;
    Apartment Ap18("sjhdg", "Cordoba, Spain", "Tiny Cabin", "Located on the outskirts of the small village of Llanos de Don Juan, in Rute, Cordoba.", 4, 6, 185);
    query += Ap18;

    RoomBuilder b1;
    std::vector<std::string> a_room1 = {"refrigerator", "microwave", "coffee_maker"};
    RoomLayout room1 = b1.length(3.5f).width(4.1f).room_type("kitchen").name("kitchen 1").bed_capacity(0).l_amenities(a_room1).build();
    //std::cout<<room1;

    RoomBuilder b2;
    std::vector<std::string> a_room2 = {"towels", "hygiene_products", "hair_dryer", "shower"};
    RoomLayout room2 = b2.length(3.4f).width(2).room_type("bathroom").name("bathroom 1").bed_capacity(0).l_amenities(a_room2).build();

    RoomBuilder b3;
    std::vector<std::string> a_room3 = {"tv"};
    RoomLayout room3 = b3.length(4.5f).width(6).room_type("living room").name("living room 1").bed_capacity(4).l_amenities(a_room3).build();

    RoomBuilder b4;
    std::vector<std::string> a_room4 = {"air_conditioning", "heating", "bed_sheets"};
    RoomLayout room4 = b4.length(5).width(3.6f).room_type("bedroom").name("bedroom 1").bed_capacity(2).l_amenities(a_room4).build();

    ApartmentLayout Ap_layout(4, 2);
    auto ptr_room1 = std::make_shared<RoomLayout>(room1);
    auto ptr_room2 = std::make_shared<RoomLayout>(room2);
    auto ptr_room3 = std::make_shared<RoomLayout>(room3);
    auto ptr_room4 = std::make_shared<RoomLayout>(room4);

    Ap_layout.addRoom(ptr_room1);
    Ap_layout.addRoom(ptr_room2);
    Ap_layout.addRoom(ptr_room3);
    Ap_layout.addRoom(ptr_room4);

    ApartmentListingPost<std::string, 25> Ap_post;

    auto apt = std::make_shared<Apartment>(Ap18);
    auto apt_layout = std::make_shared<ApartmentLayout>(Ap_layout);

    auto *ptr_comm1_post_Ap = new Post<std::string, 25>("Samuel's travelling blog", "Extremely pleased with our stay");
    auto *ptr_comm2_post_Ap = new Post<std::string, 25>("Iris the Adventurer", "Shame we couldn't stay any longer");

    ApartmentListingPost<std::string, 25> Ap_post2;

    auto *ptr_comm3_post_Ap = new Post<std::string, 25>("Anastasia", "It was an absolute pleasure to stay at Lorenzo's cabin.");
    auto *ptr_comm4_post_Ap = new Post<std::string, 25>("Olivier", "A piece of paradise on earth!");
    auto *ptr_comm5_post_Ap = new Post<std::string, 25>("Jonas from Netherlands", "Very great place!!");

    Apartment Ap19("hsbdj", "Arbatax, Italy", "Entire villa", "Immersed in a splendid bay of Porto Frailis, our villa is a haven of tranquillity, the dream of every traveler looking for a relaxing holiday.", 5, 8, 280);
    // for some reason the description in the beginning is slightly corrupted
    query += Ap19;
    RoomBuilder b5;
    std::vector<std::string> a_room5 = {"bed_sheets"};
    RoomLayout room5 = b5.length(6).width(3.1f).room_type("bedroom").name("bedroom 2").bed_capacity(2).l_amenities(a_room5).build();
    ApartmentLayout Ap_layout2(3, 5);

    auto ptr_room5 = std::make_shared<RoomLayout>(room5);
    Ap_layout2.addRoom(ptr_room5);

    auto apt2 = std::make_shared<Apartment>(Ap19);
    auto apt_layout2 = std::make_shared<ApartmentLayout>(Ap_layout2);

    std::vector<int> v = {2, 4, 3};
    std::list<std::shared_ptr<Post<std::string, 25>>> result2;

    std::list<std::shared_ptr<Post<std::string, 25>>> l_comm_Ap_post;

    VacationPackagePost<std::string, 25> deal1;
    auto *ptr_deal_preview = new Post<std::string, 25>;
    auto *ptr_deal_tour1 = new Post<std::string, 25>;
    auto *ptr_deal_tour2 = new Post<std::string, 25>;
    auto *ptr_deal_tour3 = new Post<std::string, 25>;
    auto *ptr_Ap_post2 = &Ap_post2;

    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    std::cout<<"Welcome to our apartment rental management system! Are you looking to rent an apartment while travelling OR would you like to put your apartment up for rent? Then, you're in the right place."<<std::endl;
    /*std::cout<<"Press Enter twice to continue browsing.";
    std::cin.get(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout<<std::endl<<"An interactive menu will be displayed to improve your user experience."<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout<<"------- These are all of the apartments listed on our platform so far: -------"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    // using getters to get rid of [unusedFunction] cppcheck error
    std::vector<Apartment> vec_apts = query.getApts();
    for(const auto &apt_: vec_apts)
    {
        std::cout<<apt_<<std::endl;
    }

    User current_user;
    Reservation r;
    int choice_differentiate_users;
    bool credentials = false, booked = false;
    std::cout<<std::endl<<std::endl<<"Please select your choice of browsing: "<<std::endl;
    std::cout<<"1. Search for an apartment to rent\n2. Update/ upload details about an apartment I own\n3. Beta version for developers"<<std::endl;
    std::cin>>choice_differentiate_users; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<std::endl<<"Loading..."<<std::endl;
    switch(choice_differentiate_users)
    {
        case 1:
            std::cout<<"------- Tenant's view -------"<<std::endl;
            do{
                query.proceedTransaction(booked);
            } while(!booked);
            std::cout<<"Last step of your booking is to create an account and to specify your card details."<<std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin>>current_user;
            User::loginMenu(current_user, credentials);
            std::cout<<std::endl<<"Account was created successfully. Your account details:"<<std::endl;
            std::cout<<current_user<<std::endl;
            std::cin>>r;
            // using getters to get rid of [unusedFunction] cppcheck error
            std::cout<<std::endl<<"These are your card details: "<<std::endl;
            std::cout<<"Card Number: "<<r.getCardNumber()<<std::endl;
            std::cout<<"Card Holder Name: "<<r.getCardHolderName()<<std::endl;
            std::cout<<"Card CVV: "<<r.getCardCVV()<<std::endl;
            std::cout<<std::endl<<"Payment received. Thank you for choosing our platform!"<<std::endl;
            break;
        case 2:
            std::cout<<"------- Host's View -------"<<std::endl;
            std::cout<<"You must create an account before proceeding to upload details about an apartment."<<std::endl;
            std::cin>>current_user;
            User::loginMenu(current_user, credentials);
            if(credentials)
            {
                std::cout<<" Account was created successfully. Your account details:"<<std::endl;
                //std::cout<<current_user<<std::endl;

                // using getters to get rid of [unusedFunction] cppcheck error
                std::cout<<"Username: "<<current_user.getUsername()<<std::endl;
                std::cout<<"Password: "<<current_user.getPassword()<<std::endl;
                std::cout<<"First Name: "<<current_user.getFirstName()<<std::endl;
                std::cout<<"Last Name: "<<current_user.getLastName()<<std::endl;
                std::cout<<"Email: "<<current_user.getEmail()<<std::endl;
                std::cout<<"ID Number: "<<current_user.getIDNumber()<<std::endl;
                std::cout<<"ID Residence: "<<current_user.getIDResidence()<<std::endl;
                std::cout<<"Phone Number: "<<current_user.getPhoneNumber()<<std::endl;
                std::cout<<std::endl<<"How many apartments will your portfolio contain? Enter the number of apartments you would like to list on the market."<<std::endl;
                std::cout<<"Number of apartments to list: ";
                int no_apts;
                std::cin>>no_apts;
                std::vector<Apartment> vec_host_apts;

                // reading n objects
                for(int i = 0; i < no_apts; i++)
                {
                    Apartment Ap;
                    std::cin>>Ap;
                    query += Ap;
                    vec_host_apts.push_back(Ap);
                    std::this_thread::sleep_for(std::chrono::milliseconds(250));
                    std::cout<<"The apartment added to your portfolio contains a total of "<<Ap.getNoRooms()<<" rooms."<<std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    std::cout<<"An apartment layout will be created in order to display a user-friendly floor plan of your listed apartment."<<std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                    ApartmentLayout *ptr_l1;
                    ptr_l1 = new ApartmentLayout();
                    std::cout<<"You will be prompted to enter some details about the rooms' layouts in order to display the exact details and amenities included."<<std::endl;
                    int k = 0;
                    while(k < Ap.getNoRooms())
                    {
                        std::cout<<std::endl<<"Enter details for a new room: "<<std::endl;
                        RoomLayout *room;
                        room = new RoomLayout();
                        room->createRoom(ptr_l1);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        std::cout<<std::endl<<"These are all of the rooms that match the specific room type:";
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        for(const auto &item: ptr_l1->getRooms())
                        {
                            /*RoomLayout *ptr_room;
                            ptr_room = dynamic_cast<RoomLayout *>(item);*/
                            auto ptr_room = std::dynamic_pointer_cast<RoomLayout>(std::const_pointer_cast<Layout>(item));
                            if(ptr_room)
                            {
                                if(ptr_room->getRoomType() == room->getRoomType())
                                {
                                    if(ptr_room->getName() == room->getName())
                                    {
                                        std::cout<<std::endl<<std::endl<<"The room '"<<room->getName()<<"' has been added to the apartment layout. These are the room's details: "<<std::endl;
                                    }
                                    std::cout<<*ptr_room;
                                }
                            }
                        }
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        std::cout<<std::endl<<"You have currently entered a total of: "<<ApartmentLayout::getNoBedrooms()<<" bedrooms, "<<ApartmentLayout::getNoLivingRooms()<<" living rooms, "<<ApartmentLayout::getNoKitchens()<<" kitchens and "<<ApartmentLayout::getNoBathrooms()<<" bathrooms."<<std::endl;
                        k++;
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        std::cout<<"You have a remaining of "<<Ap.getNoRooms() - k<<" rooms to add."<<std::endl;
                    }
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                    std::cout<<std::endl<<"These are all of the items included in the apartment layout for apartment ID "<<Ap.getApartmentID()<<":"<<std::endl<<std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    for (const auto& item : ptr_l1->getRooms())
                    {
                        std::cout << *item;
                    }
                    std::cout<<std::endl;
                    std::cin>>*ptr_l1;
                    ptr_l1->drawFloorPlan();
                    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                    std::cout<<std::endl<<*ptr_l1;
                    // downcasting
                    Layout *ptr_layout = ptr_l1;
                    std::cout<<std::endl<<"The apartment's layout has a total of "<<ptr_layout->computeArea()<<" square meters of usable surface area"<<std::endl;

                    ApartmentLayout::resetStaticVariables();
                    delete ptr_l1;
                }
                std::cout<<"Added successfully to the catalog."<<std::endl;

                // displaying n objects (n is being represented by the size of vector l_apt_layouts)
                std::cout<<std::endl<<"Your apartment/s details are:"<<std::endl;
                for(int i = 0; i < no_apts; i++)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(800));
                    std::cout<<vec_host_apts[i]<<std::endl;
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                std::cout<<"Would you like to see the updated version of the latest listed apartments?"<<std::endl;
                std::cout<<"1. Yes\n2. No"<<std::endl;
                int choice_display;
                std::cin>>choice_display;
                if(choice_display == 1)
                {
                    std::cout<<query;
                }
                std::cout<<std::endl<<"Thank you for choosing our platform!"<<std::endl;
            } else
            {
                std::cout<<" Account was not created. Stop and run this script again."<<std::endl;
            }
            break;
        case 3:
            // testing template by using different typenames
            welcome_post.push("Our platform offers many choices for both tenants and hosts");
            welcome_post.push("Make the most of your stay by browsing our platform");
            welcome_post.push("Find the best apartments to stay in for your vacation spent abroad!");
            welcome_post.pop();
            welcome_post.push("Our catalog offers a wide range of unique locations and plenty of accommodations");
            welcome_post.push("Book an apartment today!");
            std::cout<<welcome_post;

            goodbye_post.push("Thank you for browsing our platform");
            goodbye_post.pop();
            goodbye_post.push("Please tell us about your experience so far");
            goodbye_post.push("Sad to see you go");
            goodbye_post.pop();
            goodbye_post.push("If you have booked any apartment, make sure to leave a review on the host's page");
            std::cout<<goodbye_post;

            quality_score.push(9);
            quality_score.push(1);
            quality_score.pop();
            quality_score.push(7);
            quality_score.push(8);
            std::cout<<quality_score;

            rating.push(4.4f);
            rating.push(4.78f);
            rating.pop();
            rating.push(4.45f);
            rating.push(4.9f);
            std::cout<<rating;

            apt_listing1.push(Ap18);
            std::cout<<apt_listing1;

            Ap_layout.setMatrixLayout(0, 1, room1.getName());
            Ap_layout.setMatrixLayout(1, 1, room2.getName());
            Ap_layout.setMatrixLayout(2, 0, room3.getName());
            Ap_layout.setMatrixLayout(3, 1, room4.getName());
            //std::cout<<Ap_layout<<std::endl;
            //Ap_layout.displayFloorPlan();

            Ap_post.readFromPost(std::cin);

            Ap_post.setApartmentPair(apt, apt_layout);

            ptr_comm1_post_Ap->push("Lovely stay.");
            ptr_comm1_post_Ap->push("Very helpful and responsive host; went out of his way to accommodate a same-day booking, which we appreciated greatly.");
            ptr_comm1_post_Ap->push("The home is cozy, quiet, and comfortable.");
            ptr_comm1_post_Ap->push("We would stay here again. Thank you!");

            ptr_comm2_post_Ap->push("This is truly an idyllic location.");
            ptr_comm2_post_Ap->push("Beautiful surroundings, peace and quiet.");
            ptr_comm2_post_Ap->push("The interior setting was extra clean and well-maintained.");
            ptr_comm2_post_Ap->push("It was a bit cool at night still, but the host was kind and put on all of the heating for us so we were fine.");
            ptr_comm2_post_Ap->push("The main road is closed for work, which means it's a very small inconvenience to get there, but the host was thoughtful about notifying you of this inconvenience before arrival!");
            ptr_comm2_post_Ap->push("Overall everything was as expected and we the host was responsive to all of our needs.");
            Ap_post.addPost(ptr_comm1_post_Ap);
            Ap_post.addPost(ptr_comm2_post_Ap);

            // testing the assignment operator
            Ap_post2 = Ap_post;

            // adding data specific only to Ap_post
            Ap_post.push("Our cabin is also an ideal starting point for exploring the beauties of Cordoba");
            Ap_post.push("Prepare to immerse yourself in the local culture and traditions.");
            ptr_comm2_post_Ap->push("Great recommendation for this home!");

            ptr_comm3_post_Ap->push("Lorenzo was very friendly and responsive, and even offered to pick me up from the bus station!");
            ptr_comm3_post_Ap->push("Gorgeous terraces with sea views, very peaceful and private, spacious and airy, with lots of natural light, super clean and has all the amenities you could possibly need.");
            ptr_comm3_post_Ap->push("We really enjoyed Hans restaurant recommendation as well.");
            ptr_comm3_post_Ap->push("Can't recommend it enough and will definitely be back!");
            Ap_post.addPost(ptr_comm3_post_Ap);

            ptr_comm4_post_Ap->push("How we loved staying with these two fantastic people. Nothing was too much for them.");
            ptr_comm4_post_Ap->push("Delicious food, delicious aperos, delicious wine tasting, perfect room, beautiful view, sweet dogs, ...");
            ptr_comm4_post_Ap->push("The room was perfect and the pool with the view was even better.");
            ptr_comm4_post_Ap->push("The highlight of our trip though was our host's hospitality - take him up on his offer for a home cooked 4-course dinner.");
            ptr_comm4_post_Ap->push("Lorenzo is an excellent cook and so we ate there every night, the food was amazing. We also did a cooking lesson which was great!");
            ptr_comm4_post_Ap->push("For example, they had fantastic lamb roasts, the perfect wine, a sea bag, and vegetables and olive oil from the garden/own production.");
            Ap_post.addPost(ptr_comm4_post_Ap);

            ptr_comm5_post_Ap->push("Hosts and helpers are very supportive and warm-hearted, which makes it very homely right away.");
            ptr_comm5_post_Ap->push("Get lots of tips for things to do and otherwise they were extremely friendly.");
            ptr_comm5_post_Ap->push("Perfect location, a stone's throw from the sea.");
            Ap_post.addPost(ptr_comm5_post_Ap);

            Ap_layout2.addRoom(ptr_room1);
            Ap_layout2.addRoom(ptr_room2);
            Ap_layout2.addRoom(ptr_room3);
            Ap_layout2.addRoom(ptr_room4);

            Ap_layout2.setMatrixLayout(0, 0, room1.getName());
            Ap_layout2.setMatrixLayout(2, 4, room2.getName());
            Ap_layout2.setMatrixLayout(1, 2, room3.getName());
            Ap_layout2.setMatrixLayout(1, 1, room4.getName());
            Ap_layout2.setMatrixLayout(1, 3, room5.getName());

            Ap_post2.setApartmentPair(apt2, apt_layout2);

            // testing the assignment operator
            //Ap_post = Ap_post2;

            std::cout<<Ap_post<<std::endl<<Ap_post2;

            // testing moveCommentsFront
            std::cout<<"Comments from Ap_post of indexes 2, 4, 3 respectively are being pushed to the from of the comment section:"<<std::endl;
            Ap_post.moveCommentsFront(v);
            result2 = Ap_post.getListComments();
            for(const auto &it : result2)
            {
                std::cout<<*it<<" ";
            }
            std::cout<<std::endl;
            // original order: (0)Samuel, (1)Iris, (2)Anastasia, (3)Olivier, (4)Jonas =>index 2: (0)Anastasia, (1)Samuel, (2)Iris, (3)Olivier, (4)Jonas =>index 4: (0)Jonas, (1)Anastasia, (2)Samuel, (3)Iris, (4)Olivier =>index 3: (0)Iris, (1)Jonas, (2)Anastasia, (3)Samuel, (4)Olivier (without host replies)

            // testing addHostReplies
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            int choice_comm;
            std::cout<<"You are now the host of Ap18 which is listed as Ap_post on our platform, enter the amount of comments you would like to reply to in the comment section:";
            std::cin>>choice_comm;
            while(choice_comm > 0)
            {
                Ap_post.addHostReplies();
                choice_comm--;
            }
            for(const auto &it : Ap_post.getListComments())
            {
                std::cout<<*it<<" ";
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            // testing sort comment section
            // https://www.walletfox.com/course/sortvectorofcustomobjects11.php
            // lambda function [captures] (argument list) -> return-type
            // captures the variables that a lambda expression can obtain (capture) from the surrounding scope
            l_comm_Ap_post = Ap_post.getListComments();
            int sort_choice;
            std::cout<<"Enter the sorting method for the comment section withing the current apartment listing post (1 - StackHeight, 2 - Title): ";
            std::cin>>sort_choice; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            l_comm_Ap_post.sort([&sort_choice](const auto& post1, const auto& post2) {
                switch(sort_choice)
                {
                    case 1:
                        return Post<std::string, 25>::sortCommentsCriteria(*post1, *post2, Property::StackHeight);
                    case 2:
                        return Post<std::string, 25>::sortCommentsCriteria(*post1, *post2, Property::Title);
                    default:
                        return false;
                }
            });
            std::cout<<"The comments section of Ap_post sorted by ";
            switch(sort_choice)
            {
                case 1:
                    std::cout<<"StackHeight:"<<std::endl;
                    break;
                case 2:
                    std::cout<<"Title:"<<std::endl;
                    break;
                default:
                    break;
            }
            for(const auto &ptr_post : l_comm_Ap_post)
            {
                std::cout<<*ptr_post<<std::endl;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cin>>deal1;
            deal1.push("Our deal is one of a kind");
            deal1.push("You should consider us to help you experience your dream vacation");
            ptr_deal_preview->setAuthor(deal1.getAuthor());
            ptr_deal_preview->setTitle("Vacation package 1 preview");
            ptr_deal_preview->push("The price ranges between 10 and 100 euros for all of the included activities");
            ptr_deal_preview->push("Here are some Must-Do experiences in Arbatax, Italy including accommodation, restaurants and tours");
            deal1.addPost(PackageType::Affordable, ptr_deal_preview);
            ptr_deal_tour1->push("Helios Turismo");
            ptr_deal_tour1->push("495 reviews");
            ptr_deal_tour1->push("#1 of 20 Boat Tours & Water Sports in Arbatax");
            ptr_deal_tour1->push("Amazing tour to the most beautiful spots of the coast north of Arbatax");
            ptr_deal_tour1->push("Visitors can expect a well-organized itinerary that covers significant landmarks and local attractions");
            ptr_deal_tour1->push("It is an unique experience which showcases the beauty and charm of Sardinia");
            ptr_deal_tour1->push("You can explore caves in groups of maximum 12 people while being guided by our crew");
            deal1.addPost(PackageType::Affordable, ptr_deal_tour1);
            deal1.addPost(PackageType::Adventure, ptr_deal_tour1);
            ptr_deal_tour2->push("StS Ogliastra, Centro Servizi Turistici");
            ptr_deal_tour2->push("53 reviews");
            ptr_deal_tour2->push("#2 of 11 things to do in Arbatax");
            ptr_deal_tour2->push("STS Ogliastra is an experienced information centre in Arbatax");
            ptr_deal_tour2->push("We promote all the local excursions by sea and by land");
            ptr_deal_tour2->push("The included tickets are for the Little Green Train, boat tours on the Golf of Orosei, guided trekking and much more");
            ptr_deal_tour2->push("Furthermore you can find info on local transport services, accommodation, activities and events in the area to assist you in creating an unforgetable Sardinian holiday");
            deal1.addPost(PackageType::Adventure, ptr_deal_tour2);
            ptr_deal_tour3->push("Rocce rosse");
            ptr_deal_tour3->push("730 reviews");
            ptr_deal_tour3->push("Points of Interest & Landmarks in Arbatax");
            ptr_deal_tour3->push("A beautiful place to hike or sit and just be in nature");
            ptr_deal_tour3->push("Parking is free & directly opposite one of the formations, the main one is a flat & easy 50 meters away");
            ptr_deal_tour3->push("The rock formation is beautiful and sometimes there are people use the rocks as jumping point in the sea");
            ptr_deal_tour3->push("Take the trip at the end of the day, the sunset and the colour of the stones makes it a beautiful place to take pictures to remember");
            deal1.addPost(PackageType::Adventure, ptr_deal_tour3);
            deal1.addPost(PackageType::BeachResort, ptr_deal_tour3);
            deal1.addPost(PackageType::AllInclusive, ptr_Ap_post2);
            std::cout<<deal1;
            break;
        default:
            return 0;
    }
    delete ptr_deal_tour3;
    delete ptr_deal_tour2;
    delete ptr_deal_tour1;
    delete ptr_deal_preview;
    delete ptr_comm5_post_Ap;
    delete ptr_comm4_post_Ap;
    delete ptr_comm3_post_Ap;
    delete ptr_comm2_post_Ap;
    delete ptr_comm1_post_Ap;

    /** PROJECT 2 **/
    /*
    Apartment Ap1("12rg3g0", "Benidorm, Spain", "Rental Unit", "Apartment Ideal to enjoy Playa de Benidorm, in the heart of Playa de Poniente. Views from the living room to the ocean and the Isle of Benidorm.", 4, 5, 136);
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    std::cout<<"The apartment added to your portfolio contains a total of "<<Ap1.getNoRooms()<<" rooms."<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout<<"An apartment layout will be created in order to display a user-friendly floor plan of your listed apartment."<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    ApartmentLayout *ptr_l1;
    ptr_l1 = new ApartmentLayout();
    std::cout<<"You will be prompted to enter some details about the rooms' layouts in order to display the exact details and amenities included."<<std::endl;
    int k = 0;
    while(k < Ap1.getNoRooms())
    {
        std::cout<<std::endl<<"Enter details for a new room: "<<std::endl;
        RoomLayout *room;
        room = new RoomLayout();
        room->createRoom(ptr_l1);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout<<std::endl<<"These are all of the rooms that match the specific room type:";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        for(const auto &item: ptr_l1->getRooms())
        {
            if(dynamic_cast<RoomLayout *>(item)->getRoomType() == room->getRoomType())
            {
                if(dynamic_cast<RoomLayout *>(item)->getName() == room->getName())
                {
                    std::cout<<std::endl<<std::endl<<"The room '"<<room->getName()<<"' has been added to the apartment layout. These are the room's details: "<<std::endl;
                }
                std::cout<<*item;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout<<std::endl<<"You have currently entered a total of: "<<ApartmentLayout::getNoBedrooms()<<" bedrooms, "<<ApartmentLayout::getNoLivingRooms()<<" living rooms, "<<ApartmentLayout::getNoKitchens()<<" kitchens and "<<ApartmentLayout::getNoBathrooms()<<" bathrooms."<<std::endl;
        k++;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout<<"You have a remaining of "<<Ap1.getNoRooms() - k<<" rooms to add."<<std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout<<std::endl<<"These are all of the items included in the apartment layout for apartment ID "<<Ap1.getApartmentID()<<":"<<std::endl<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    for(const auto &item: ptr_l1->getRooms())
    {
        std::cout<<*item;
    }
    std::cout<<std::endl;
    std::cin>>*ptr_l1;
    ptr_l1->drawFloorPlan();
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout<<std::endl<<*ptr_l1;
    // downcasting
    Layout *ptr_layout = ptr_l1;
    std::cout<<std::endl<<"The apartment's layout has a total of "<<ptr_layout->computeArea()<<" square meters of usable surface area"<<std::endl;
    delete ptr_l1;
    return 0;
     */

    /** PROJECT 3 **/
    /*// testing template by using different typenames
    Post<std::string, 25> welcome_post("Andra Alexandrescu", "Welcome message!");
    welcome_post.push("Our platform offers many choices for both tenants and hosts");
    welcome_post.push("Make the most of your stay by browsing our platform");
    welcome_post.push("Find the best apartments to stay in for your vacation spent abroad!");
    welcome_post.pop();
    welcome_post.push("Our catalog offers a wide range of unique locations and plenty of accommodations");
    welcome_post.push("Book an apartment today!");
    std::cout<<welcome_post;
    Post<std::string, 25> goodbye_post;
    goodbye_post.push("Thank you for browsing our platform");
    goodbye_post.pop();
    goodbye_post.push("Please tell us about your experience so far");
    goodbye_post.push("Sad to see you go");
    goodbye_post.pop();
    goodbye_post.push("If you have booked any apartment, make sure to leave a review on the host's page");
    std::cout<<goodbye_post;
    Post<int, 10> quality_score;
    quality_score.push(9);
    quality_score.push(1);
    quality_score.pop();
    quality_score.push(7);
    quality_score.push(8);
    std::cout<<quality_score;
    Post<float, 10> rating;
    rating.push(4.4);
    rating.push(4.78);
    rating.pop();
    rating.push(4.45);
    rating.push(4.9);
    std::cout<<rating;
    Post<Apartment, 1> apt_listing1;
    Apartment Ap18("sjhdg", "Cordoba, Spain", "Tiny Cabin", "Located on the outskirts of the small village of Llanos de Don Juan, in Rute, Cordoba.", 4, 6, 185);
    query += Ap18;
    apt_listing1.push(Ap18);
    std::cout<<apt_listing1;
    RoomBuilder b1;
    std::vector<std::string> a_room1 = {"refrigerator", "microwave", "coffee_maker"};
    RoomLayout room1 = b1.length(3.5).width(4.1).room_type("kitchen").name("kitchen 1").bed_capacity(0).l_amenities(a_room1).build();
    //std::cout<<room1;
    RoomBuilder b2;
    std::vector<std::string> a_room2 = {"towels", "hygiene_products", "hair_dryer", "shower"};
    RoomLayout room2 = b2.length(3.4).width(2).room_type("bathroom").name("bathroom 1").bed_capacity(0).l_amenities(a_room2).build();
    RoomBuilder b3;
    std::vector<std::string> a_room3 = {"tv"};
    RoomLayout room3 = b3.length(4.5).width(6).room_type("living room").name("living room 1").bed_capacity(4).l_amenities(a_room3).build();
    RoomBuilder b4;
    std::vector<std::string> a_room4 = {"air_conditioning", "heating", "bed_sheets"};
    RoomLayout room4 = b4.length(5).width(3.6).room_type("bedroom").name("bedroom 1").bed_capacity(2).l_amenities(a_room4).build();
    ApartmentLayout Ap_layout(4, 2);
    RoomLayout *ptr_room1 = &room1; Ap_layout.addRoom(ptr_room1);
    RoomLayout *ptr_room2 = &room2; Ap_layout.addRoom(ptr_room2);
    RoomLayout *ptr_room3 = &room3; Ap_layout.addRoom(ptr_room3);
    RoomLayout *ptr_room4 = &room4; Ap_layout.addRoom(ptr_room4);
    Ap_layout.setMatrixLayout(0, 1, room1.getName());
    Ap_layout.setMatrixLayout(1, 1, room2.getName());
    Ap_layout.setMatrixLayout(2, 0, room3.getName());
    Ap_layout.setMatrixLayout(3, 1, room4.getName());
    //std::cout<<Ap_layout<<std::endl;
    //Ap_layout.displayFloorPlan();
    ApartmentListingPost<std::string, 25> Ap_post;
    Ap_post.readFromPost(std::cin);
    Apartment *apt = &Ap18;
    ApartmentLayout *apt_layout = &Ap_layout;
    Ap_post.setApartmentPair(apt, apt_layout);
    auto *ptr_comm1_post_Ap = new Post<std::string, 25>("Samuel's travelling blog", "Extremely pleased with our stay");
    ptr_comm1_post_Ap->push("Lovely stay.");
    ptr_comm1_post_Ap->push("Very helpful and responsive host; went out of his way to accommodate a same-day booking, which we appreciated greatly.");
    ptr_comm1_post_Ap->push("The home is cozy, quiet, and comfortable.");
    ptr_comm1_post_Ap->push("We would stay here again. Thank you!");
    auto *ptr_comm2_post_Ap = new Post<std::string, 25>("Iris the Adventurer", "Shame we couldn't stay any longer");
    ptr_comm2_post_Ap->push("This is truly an idyllic location.");
    ptr_comm2_post_Ap->push("Beautiful surroundings, peace and quiet.");
    ptr_comm2_post_Ap->push("The interior setting was extra clean and well-maintained.");
    ptr_comm2_post_Ap->push("It was a bit cool at night still, but the host was kind and put on all of the heating for us so we were fine.");
    ptr_comm2_post_Ap->push("The main road is closed for work, which means it's a very small inconvenience to get there, but the host was thoughtful about notifying you of this inconvenience before arrival!");
    ptr_comm2_post_Ap->push("Overall everything was as expected and we the host was responsive to all of our needs.");
    Ap_post.addPost(ptr_comm1_post_Ap);
    Ap_post.addPost(ptr_comm2_post_Ap);
    // testing the copy constructor
    ApartmentListingPost<std::string, 25> Ap_post2(Ap_post);
    // adding data specific only to Ap_post
    Ap_post.push("Our cabin is also an ideal starting point for exploring the beauties of Cordoba");
    Ap_post.push("Prepare to immerse yourself in the local culture and traditions.");
    ptr_comm2_post_Ap->push("Great recommendation for this home!");
    auto *ptr_comm3_post_Ap = new Post<std::string, 25>("Anastasia", "It was an absolute pleasure to stay at Lorenzo's cabin.");
    ptr_comm3_post_Ap->push("Lorenzo was very friendly and responsive, and even offered to pick me up from the bus station!");
    ptr_comm3_post_Ap->push("Gorgeous terraces with sea views, very peaceful and private, spacious and airy, with lots of natural light, super clean and has all the amenities you could possibly need.");
    ptr_comm3_post_Ap->push("We really enjoyed Hans restaurant recommendation as well.");
    ptr_comm3_post_Ap->push("Can't recommend it enough and will definitely be back!");
    Ap_post.addPost(ptr_comm3_post_Ap);
    auto *ptr_comm4_post_Ap = new Post<std::string, 25>("Olivier", "A piece of paradise on earth!");
    ptr_comm4_post_Ap->push("How we loved staying with these two fantastic people. Nothing was too much for them.");
    ptr_comm4_post_Ap->push("Delicious food, delicious aperos, delicious wine tasting, perfect room, beautiful view, sweet dogs, ...");
    ptr_comm4_post_Ap->push("The room was perfect and the pool with the view was even better.");
    ptr_comm4_post_Ap->push("The highlight of our trip though was our host's hospitality - take him up on his offer for a home cooked 4-course dinner.");
    ptr_comm4_post_Ap->push("Lorenzo is an excellent cook and so we ate there every night, the food was amazing. We also did a cooking lesson which was great!");
    ptr_comm4_post_Ap->push("For example, they had fantastic lamb roasts, the perfect wine, a sea bag, and vegetables and olive oil from the garden/own production.");
    Ap_post.addPost(ptr_comm4_post_Ap);
    auto *ptr_comm5_post_Ap = new Post<std::string, 25>("Jonas from Netherlands", "Very great place!!");
    ptr_comm5_post_Ap->push("Hosts and helpers are very supportive and warm-hearted, which makes it very homely right away.");
    ptr_comm5_post_Ap->push("Get lots of tips for things to do and otherwise they were extremely friendly.");
    ptr_comm5_post_Ap->push("Perfect location, a stone's throw from the sea.");
    Ap_post.addPost(ptr_comm5_post_Ap);
    Apartment Ap19("hsbdj", "Arbatax, Italy", "Entire villa", "Immersed in a splendid bay of Porto Frailis, our villa is a haven of tranquillity, the dream of every traveler looking for a relaxing holiday.", 5, 8, 280);
    // for some reason the description in the beginning is slightly corrupted
    query += Ap19;
    RoomBuilder b5;
    std::vector<std::string> a_room5 = {"bed_sheets"};
    RoomLayout room5 = b5.length(6).width(3.1).room_type("bedroom").name("bedroom 2").bed_capacity(2).l_amenities(a_room5).build();
    ApartmentLayout Ap_layout2(3, 5);
    Ap_layout2.addRoom(ptr_room1);
    Ap_layout2.addRoom(ptr_room2);
    Ap_layout2.addRoom(ptr_room3);
    Ap_layout2.addRoom(ptr_room4);
    RoomLayout *ptr_room5 = &room5; Ap_layout2.addRoom(ptr_room5);
    Ap_layout2.setMatrixLayout(0, 0, room1.getName());
    Ap_layout2.setMatrixLayout(2, 4, room2.getName());
    Ap_layout2.setMatrixLayout(1, 2, room3.getName());
    Ap_layout2.setMatrixLayout(1, 1, room4.getName());
    Ap_layout2.setMatrixLayout(1, 3, room5.getName());
    Apartment *apt2 = &Ap19;
    ApartmentLayout *apt_layout2 = &Ap_layout2;
    Ap_post2.setApartmentPair(apt2, apt_layout2);
    // testing the assignment operator
    //Ap_post = Ap_post2;
    std::cout<<Ap_post<<std::endl<<Ap_post2;
    // testing moveCommentsFront
    std::cout<<"Comments from Ap_post of indexes 2, 4, 3 respectively are being pushed to the from of the comment section:"<<std::endl;
    std::vector<int> v = {2, 4, 3};
    Ap_post.moveCommentsFront(v);
    std::list<Post<std::string, 25>*> result2 = Ap_post.getListComments();
    for(Post<std::string, 25> *&it : result2)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    // original order: (0)Samuel, (1)Iris, (2)Anastasia, (3)Olivier, (4)Jonas =>index 2: (0)Anastasia, (1)Samuel, (2)Iris, (3)Olivier, (4)Jonas =>index 4: (0)Jonas, (1)Anastasia, (2)Samuel, (3)Iris, (4)Olivier =>index 3: (0)Iris, (1)Jonas, (2)Anastasia, (3)Samuel, (4)Olivier
    // testing sort comment section
    // https://www.walletfox.com/course/sortvectorofcustomobjects11.php
    // lambda function [captures] (argument list) -> return-type
    // captures the variables that a lambda expression can obtain (capture) from the surrounding scope
    std::list<Post<std::string, 25> *> l_comm_Ap_post = Ap_post.getListComments();
    int sort_choice;
    std::cout<<"Enter the sorting method for the comment section withing the current apartment listing post (1 - StackHeight, 2 - Title): ";
    std::cin>>sort_choice; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    l_comm_Ap_post.sort([&sort_choice](const auto& post1, const auto& post2) {
        switch(sort_choice)
        {
            case 1:
                return Post<std::string, 25>::sortCommentsCriteria(*post1, *post2, Property::StackHeight);
            case 2:
                return Post<std::string, 25>::sortCommentsCriteria(*post1, *post2, Property::Title);
            default:
                break;
        }
    });
    std::cout<<"The comments section of Ap_post sorted by ";
    switch(sort_choice)
    {
        case 1:
            std::cout<<"StackHeight:"<<std::endl;
            break;
        case 2:
            std::cout<<"Title:"<<std::endl;
            break;
        default:
            break;
    }
    for (const auto& ptr_post : l_comm_Ap_post)
    {
        std::cout<<*ptr_post<<std::endl;
    }
    // testing addHostReplies
    int choice_comm;
    std::cout<<"You are now the host of Ap18 which is listed as Ap_post on our platform, enter the amount of comments you would like to reply to in the comment section:";
    std::cin>>choice_comm;
    while(choice_comm > 0)
    {
        Ap_post.addHostReplies();
        choice_comm--;
    }
    std::list<Post<std::string, 25>*> result = Ap_post.getListComments();
    for(Post<std::string, 25> *&it : result)
    {
        std::cout<<*it<<" ";
    }
    // testing read (since it's more powerful than readFromPost) and display functions for ApartmentListingPost
    ApartmentListingPost<std::string, 25> Ap_post0;
    std::cin>>Ap_post0;
    std::cout<<Ap_post0;
    VacationPackagePost<std::string, 25> deal1;
    std::cin>>deal1;
    deal1.push("Our deal is one of a kind");
    deal1.push("You should consider us to help you experience your dream vacation");
    auto *ptr_deal_preview = new Post<std::string, 25>;
    ptr_deal_preview->setAuthor(deal1.getAuthor());
    ptr_deal_preview->setTitle("Vacation package 1 preview");
    ptr_deal_preview->push("The price ranges between 10 and 100 euros for all of the included activities");
    ptr_deal_preview->push("Here are some Must-Do experiences in Arbatax, Italy including accommodation, restaurants and tours");
    deal1.addPost(PackageType::Affordable, ptr_deal_preview);
    auto *ptr_deal_tour1 = new Post<std::string, 25>;
    ptr_deal_tour1->push("Helios Turismo");
    ptr_deal_tour1->push("495 reviews");
    ptr_deal_tour1->push("#1 of 20 Boat Tours & Water Sports in Arbatax");
    ptr_deal_tour1->push("Amazing tour to the most beautiful spots of the coast north of Arbatax");
    ptr_deal_tour1->push("Visitors can expect a well-organized itinerary that covers significant landmarks and local attractions");
    ptr_deal_tour1->push("It is an unique experience which showcases the beauty and charm of Sardinia");
    ptr_deal_tour1->push("You can explore caves in groups of maximum 12 people while being guided by our crew");
    deal1.addPost(PackageType::Affordable, ptr_deal_tour1);
    deal1.addPost(PackageType::Adventure, ptr_deal_tour1);
    auto *ptr_deal_tour2 = new Post<std::string, 25>;
    ptr_deal_tour2->push("StS Ogliastra, Centro Servizi Turistici");
    ptr_deal_tour2->push("53 reviews");
    ptr_deal_tour2->push("#2 of 11 things to do in Arbatax");
    ptr_deal_tour2->push("STS Ogliastra is an experienced information centre in Arbatax");
    ptr_deal_tour2->push("We promote all the local excursions by sea and by land");
    ptr_deal_tour2->push("The included tickets are for the Little Green Train, boat tours on the Golf of Orosei, guided trekking and much more");
    ptr_deal_tour2->push("Furthermore you can find info on local transport services, accommodation, activities and events in the area to assist you in creating an unforgetable Sardinian holiday");
    deal1.addPost(PackageType::Adventure, ptr_deal_tour2);
    auto *ptr_deal_tour3 = new Post<std::string, 25>;
    ptr_deal_tour3->push("Rocce rosse");
    ptr_deal_tour3->push("730 reviews");
    ptr_deal_tour3->push("Points of Interest & Landmarks in Arbatax");
    ptr_deal_tour3->push("A beautiful place to hike or sit and just be in nature");
    ptr_deal_tour3->push("Parking is free & directly opposite one of the formations, the main one is a flat & easy 50 meters away");
    ptr_deal_tour3->push("The rock formation is beautiful and sometimes there are people use the rocks as jumping point in the sea");
    ptr_deal_tour3->push("Take the trip at the end of the day, the sunset and the colour of the stones makes it a beautiful place to take pictures to remember");
    deal1.addPost(PackageType::Adventure, ptr_deal_tour3);
    deal1.addPost(PackageType::BeachResort, ptr_deal_tour3);
    auto *ptr_Ap_post2 = &Ap_post2;
    deal1.addPost(PackageType::AllInclusive, ptr_Ap_post2);
    std::cout<<deal1;
    delete ptr_comm1_post_Ap;
    delete ptr_comm2_post_Ap;
    delete ptr_comm3_post_Ap;
    delete ptr_comm4_post_Ap;
    delete ptr_comm5_post_Ap;
    delete ptr_deal_preview;
    delete ptr_deal_tour1;
    delete ptr_deal_tour2;
    delete ptr_deal_tour3;*/

    return 0;
}