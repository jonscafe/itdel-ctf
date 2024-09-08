<?php

function random(int $length = 60): string
{
    $characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    $randomString = '';

    for ($i = 0; $i < $length; $i++) {
        $randomString .= $characters[rand(0, strlen($characters) - 1)];
    }

    return $randomString;
}

function getQuote(): string
{
    $quotes = [
        "The supreme art of war is to subdue the enemy without fighting.",
        "In the midst of chaos, there is also opportunity.",
        "Appear weak when you are strong, and strong when you are weak.",
        "If your enemy is secure at all points, be prepared for him. If he is in superior strength, evade him.",
        "Let your plans be dark and impenetrable as night, and when you move, fall like a thunderbolt.",
        "All warfare is based on deception.",
        "The greatest victory is that which requires no battle.",
        "Know thy self, know thy enemy. A thousand battles, a thousand victories.",
        "Victorious warriors win first and then go to war, while defeated warriors go to war first and then seek to win.",
        "Opportunities multiply as they are seized.",
    ];

    $request_body = json_decode(file_get_contents('php://input'), true);

    if (isset($request_body['__']) && $request_body['__'] == hash('sha256', random() . time())) {
        return 'ITDEL{Tru3_V1ct0ry_fR0M_gR3AT_L3ad3r}';
    }

    return $quotes[rand(0, 9)];
}

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Art of War Quotes</title>
    <link href="https://cdnjs.cloudflare.com/ajax/libs/flowbite/2.2.1/flowbite.min.css" rel="stylesheet" />
    <script src="https://cdn.tailwindcss.com"></script>
</head>

<body class="bg-black text-white mt-10">
    <section class="bg-black">
        <div class="py-8 px-4 mx-auto max-w-screen-xl text-center">
            <h1 class="mb-4 text-4xl font-bold tracking-tight leading-none md:text-5xl lg:text-6xl text-red-600">
                <?= getQuote() ?>
            </h1>
            <p class="mb-8 text-lg font-normal lg:text-xl sm:px-16 xl:px-48 text-gray-300">
                Didn’t like this one? Generate another!
            </p>
            <div class="flex flex-col mb-8 lg:mb-16 space-y-4 sm:flex-row sm:justify-center sm:space-y-0 sm:space-x-4">
                <a href="https://en.wikipedia.org/wiki/The_Art_of_War" target="_blank" class="inline-flex justify-center items-center py-3 px-5 text-base font-medium text-white rounded-lg bg-red-600 hover:bg-red-800 focus:ring-4 focus:ring-red-300">
                    Learn More
                    <svg class="ml-2 -mr-1 w-5 h-5" fill="currentColor" viewBox="0 0 20 20" xmlns="http://www.w3.org/2000/svg">
                        <path fill-rule="evenodd" d="M10.293 3.293a1 1 0 011.414 0l6 6a1 1 0 010 1.414l-6 6a1 1 0 01-1.414-1.414L14.586 11H3a1 1 0 110-2h11.586l-4.293-4.293a1 1 0 010-1.414z" clip-rule="evenodd"></path>
                    </svg>
                </a>
                <button onClick="window.location.reload();" class="inline-flex justify-center items-center py-3 px-5 text-base font-medium text-center text-gray-300 rounded-lg border border-gray-700 hover:bg-gray-700 focus:ring-4 focus:ring-gray-600">
                    Another One
                </button>
            </div>
        </div>
    </section>
    <section class="bg-black">
        <div class="gap-16 items-center py-8 px-4 mx-auto max-w-screen-xl lg:grid lg:grid-cols-2">
            <div class="grid grid-cols-2 gap-4">
                <img class="w-full rounded-lg" src="https://example.com/warrior-image1.jpg" alt="Warrior 1">
                <img class="mt-4 w-full lg:mt-10 rounded-lg" src="https://example.com/warrior-image2.jpg" alt="Warrior 2">
            </div>
            <div class="grid grid-cols-2 gap-4">
                <img class="w-full rounded-lg" src="https://example.com/warrior-image3.jpg" alt="Warrior 3">
                <img class="mt-4 w-full lg:mt-10 rounded-lg" src="https://example.com/warrior-image4.jpg" alt="Warrior 4">
            </div>
        </div>
    </section>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/flowbite/2.2.1/flowbite.min.js"></script>
    <script>
        tailwind.config = {
            darkMode: 'class',
            theme: {
                extend: {
                    colors: {
                        primary: {
                            "50": "#ffe5e5",
                            "100": "#ffcccc",
                            "200": "#ffb3b3",
                            "300": "#ff9999",
                            "400": "#ff6666",
                            "500": "#ff4d4d",
                            "600": "#cc3d3d",
                            "700": "#992e2e",
                            "800": "#661f1f",
                            "900": "#330f0f",
                        }
                    }
                },
                fontFamily: {
                    'body': [
                        'Cinzel', 'serif',
                    ],
                    'sans': [
                        'Cinzel', 'serif',
                    ]
                }
            }
        }
    </script>
</body>

</html>
