// Function to load character names into the select element
async function loadCharacters() {
    const characterSelect = document.getElementById('character-select');
    const characterPaths = [
        'characters/anomaly/',
        'characters/attack/',
        'characters/rupture/',
        'characters/stun/',
        'characters/support/'
    ];

    for (const path of characterPaths) {
        for (const file of files) {
                const characterData = await fetch(`${path}${file}`) // Fetch JSON file
        }
    }
}