<?php

error_reporting(0);

$output = null;

if (isset($_GET['host']) && is_string($_GET['host'])) {
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_URL, $_GET['host']);
    curl_setopt($ch, CURLOPT_TIMEOUT, 10);
    $output = curl_exec($ch);

    if ($output === false) {
        $output = "Sorry, timed out!";
    } else if (strpos($output, 'SiantarRapFoundationJelasBatakyangBicara') !== false) {
        $output = "SVRERUx7WW9vb19lc3NlcmVmZmZmZmZmX2ZvdW5kYXRpb25ubm4hIX0=";
    }
    curl_close($ch);
} else {
    $output = "URL Dulu Bos!";
}

?>

<!DOCTYPE html>
<html lang="id">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>seseref crawler</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/10.5.0/styles/default.min.css">
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/10.5.0/highlight.min.js"></script>
    <script>
        hljs.initHighlightingOnLoad();
    </script>
</head>
<!-- SiantarRapFoundationJelasBatakyangBicara -->

<body class="dark dark:bg-gray-900">
    <section class="bg-white dark:bg-gray-900">
        <div class="py-8 px-4 mx-auto max-w-screen-xxl sm:py-16 lg:px-6">
            <div class="mx-auto max-w-screen-sm text-center">
                <h2 class="mb-4 text-4xl tracking-tight font-extrabold leading-tight text-gray-900 dark:text-white">
                    Hundul Ho asa huperiksa linkmu!
                </h2>
                <form method="GET" action="">
                    <div class="mb-6 mt-4">
                        <label for="default-input" class="block mb-2 text-sm font-medium text-gray-900 dark:text-white">
                            Linkmu
                        </label>
                        <input type="text" id="default-input" name="host" class="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500">
                        <button type="submit" class="relative inline-flex items-center justify-center p-0.5 mb-2 mr-2 overflow-hidden text-sm font-medium text-gray-900 rounded-lg group bg-gradient-to-br from-cyan-500 to-blue-500 group-hover:from-cyan-500 group-hover:to-blue-500 hover:text-white dark:text-white focus:ring-4 focus:outline-none focus:ring-cyan-200 dark:focus:ring-cyan-800 mt-5">
                            <span class="relative px-5 py-2.5 transition-all ease-in duration-75 bg-white dark:bg-gray-900 rounded-md group-hover:bg-opacity-0">
                                Lao
                            </span>
                        </button>
                    </div>
                </form>
                <div class="dark:bg-gray-800 dark:border-gray-700 rounded-lg shadow-md border border-gray-200">
                    <h5 class="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white text-center">
                        Bereng
                    </h5>
                    <hr class="my-3 h-px border-0 dark:bg-gray-700">
                    <div class="rounded-lg overflow-hidden">
                        <pre class="font-normal text-gray-700 dark:text-gray-400">
                            <code class="language-html"><?php echo !empty($output) ? htmlspecialchars($output) : "No results"; ?></code>
                        </pre>
                    </div>
                </div>
            </div>
        </div>
    </section>
    <script src="https://cdn.tailwindcss.com"></script>
</body>

</html>
