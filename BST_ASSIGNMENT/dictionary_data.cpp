#include "dictionary.h"
// This is the actual implementation of the getDictionary function that was
// declared in the .h file. Its job is to create and return the vector of words.
vector<Word> getDictionary() {
    vector<Word> dictionary = {
//        Word("AA", "A medieval chemical science aiming to transmute base metals into gold."),
//        Word("BB", "A medieval chemical science aiming to transmute base metals into gold."),
//        Word("CC", "A medieval chemical science aiming to transmute base metals into gold.")
        // A
        Word("Alchemy", "A medieval chemical science aiming to transmute base metals into gold."),
        Word("Alchemy", "A medieval chemical science aiming to transmute base metals into gold."),
        Word("Ambiguous", "Open to more than one interpretation; having a double meaning."),
        Word("Anachronism", "A thing belonging to a period other than that in which it exists."),
        Word("Apex", "The top or highest part of something, especially one forming a point."),
        // B
        Word("Benevolent", "Well meaning and kindly."),
        Word("Bolster", "Support or strengthen; prop up."),
        Word("Brevity", "Concise and exact use of words in writing or speech."),
        Word("Bellicose", "Demonstrating aggression and willingness to fight."),
        // C
        Word("Catalyst", "A substance that increases the rate of a chemical reaction."),
        Word("Chronicle", "A factual written account of important or historical events."),
        Word("Clarity", "The quality of being easy to see, hear, or understand."),
        Word("Conundrum", "A confusing and difficult problem or question."),
        // D
        Word("Diligent", "Having or showing care and conscientiousness in one's work."),
        Word("Divergent", "Tending to be different or develop in different directions."),
        Word("Doctrine", "A belief or set of beliefs held and taught by a group."),
        Word("Dynamic", "Characterized by constant change, activity, or progress."),
        // E
        Word("Eccentric", "Unconventional and slightly strange."),
        Word("Eloquent", "Fluent or persuasive in speaking or writing."),
        Word("Empathy", "The ability to understand and share the feelings of another."),
        Word("Exemplary", "Serving as a desirable model; representing the best of its kind."),
        // F
        Word("Fathom", "Understand (a difficult problem or an enigmatic person) after much thought."),
        Word("Flourish", "Grow or develop in a healthy or vigorous way."),
        Word("Formidable", "Inspiring fear or respect through being impressively large or powerful."),
        Word("Frugal", "Sparing or economical with regard to money or food."),
        // G
        Word("Galvanize", "Shock or excite (someone) into taking action."),
        Word("Garrulous", "Excessively talkative, especially on trivial matters."),
        Word("Generic", "Characteristic of or relating to a class or group of things; not specific."),
        Word("Gravity", "The force that attracts a body toward the center of the earth."),
        // H
        Word("Harmony", "The quality of forming a pleasing and consistent whole."),
        Word("Hindsight", "Understanding of a situation or event only after it has happened."),
        Word("Hypothesis", "A supposition or proposed explanation made on the basis of limited evidence."),
        Word("Humane", "Having or showing compassion or benevolence."),
        // I
        Word("Idiosyncrasy", "A mode of behavior or way of thought peculiar to an individual."),
        Word("Immutable", "Unchanging over time or unable to be changed."),
        Word("Incisive", "Intelligently analytical and clear-thinking."),
        Word("Irony", "The expression of one's meaning by using language that normally signifies the opposite."),
        // J
        Word("Jargon", "Special words or expressions that are used by a particular profession or group."),
        Word("Jubilant", "Feeling or expressing great happiness and triumph."),
        Word("Juxtaposition", "The fact of two things being seen or placed close together with contrasting effect."),
        Word("Jovial", "Cheerful and friendly."),
        // K
        Word("Keen", "Having or showing eagerness or enthusiasm."),
        Word("Kinetic", "Relating to or resulting from motion."),
        Word("Kudos", "Praise and honor received for an achievement."),
        Word("Kindred", "One's family and relations."),
        // L
        Word("Labyrinth", "A complicated irregular network of passages or paths."),
        Word("Lucid", "Expressed clearly; easy to understand."),
        Word("Luminous", "Emitting or reflecting bright light."),
        Word("Legacy", "An amount of money or property left to someone in a will."),
        // M
        Word("Malleable", "Able to be hammered or pressed permanently out of shape without breaking."),
        Word("Meticulous", "Showing great attention to detail; very careful and precise."),
        Word("Momentum", "The quantity of motion of a moving body."),
        Word("Myriad", "A countless or extremely great number."),
        // N
        Word("Nebulous", "In the form of a cloud or haze; hazy, vague, or ill-defined."),
        Word("Nostalgia", "A sentimental longing for the past."),
        Word("Nuance", "A subtle difference in or shade of meaning, expression, or sound."),
        Word("Novice", "A person new to or inexperienced in a field or situation."),
        // O
        Word("Oblivious", "Not aware of or not concerned about what is happening around one."),
        Word("Opaque", "Not able to be seen through; not transparent."),
        Word("Optimize", "Make the best or most effective use of a situation or resource."),
        Word("Opulent", "Ostentatiously rich and luxurious or lavish."),
        // P
        Word("Paradox", "A seemingly absurd or self-contradictory statement that may prove to be well founded or true."),
        Word("Pinnacle", "The most successful point; the culmination."),
        Word("Pragmatic", "Dealing with things sensibly and realistically."),
        Word("Profound", "Very great or intense; having or showing great knowledge or insight."),
        // Q
        Word("Qualm", "An uneasy feeling of doubt, worry, or fear."),
        Word("Quarantine", "A state of isolation in which people or animals that may have a disease are placed."),
        Word("Query", "A question, especially one addressed to an official or organization."),
        Word("Quintessential", "Representing the most perfect or typical example of a quality or class."),
        // R
        Word("Ramification", "A consequence of an action or event, especially when complex or unwelcome."),
        Word("Resilience", "The capacity to recover quickly from difficulties; toughness."),
        Word("Rhetoric", "The art of effective or persuasive speaking or writing."),
        Word("Rudimentary", "Involving or limited to basic principles."),
        // S
        Word("Scrutinize", "Examine or inspect closely and thoroughly."),
        Word("Spontaneous", "Performed or occurring as a result of a sudden inner impulse."),
        Word("Stoic", "A person who can endure pain or hardship without showing their feelings."),
        Word("Synergy", "The interaction of elements that when combined produce a total effect that is greater than the sum of the individual elements."),
        // T
        Word("Tactful", "Having or showing sensitivity in dealing with others or with difficult issues."),
        Word("Tenacious", "Tending to keep a firm hold of something; clinging or adhering closely."),
        Word("Tranquil", "Free from disturbance; calm."),
        Word("Transient", "Lasting only for a short time; impermanent."),
        // U
        Word("Ubiquitous", "Present, appearing, or found everywhere."),
        Word("Unilateral", "Performed by or affecting only one person, group, or country involved in a particular situation."),
        Word("Utopia", "An imagined place or state of things in which everything is perfect."),
        Word("Undulate", "Move with a smooth wavelike motion."),
        // V
        Word("Validate", "Check or prove the validity or accuracy of something."),
        Word("Venerate", "Regard with great respect; revere."),
        Word("Vex", "Make (someone) feel annoyed, frustrated, or worried."),
        Word("Vibrant", "Full of energy and enthusiasm."),
        // W
        Word("Wane", "Decrease in vigor, power, or extent; become weaker."),
        Word("Whimsical", "Playfully quaint or fanciful, especially in an appealing and amusing way."),
        Word("Wistful", "Having or showing a feeling of vague or regretful longing."),
        Word("Wry", "Using or expressing dry, especially mocking, humor."),
        // X
        Word("Xenophobia", "Dislike of or prejudice against people from other countries."),
        Word("Xerophyte", "A plant which needs very little water."),
        Word("Xylophone", "A musical instrument played by striking a row of wooden bars of graduated length with one or more small mallets."),
        Word("Xenial", "Hospitable, especially to visiting strangers or foreigners."),
        // Y
        Word("Yearn", "Have an intense feeling of longing for something."),
        Word("Yield", "Produce or provide a natural, agricultural, or industrial product."),
        Word("Yoke", "A wooden crosspiece that is fastened over the necks of two animals and attached to the plow or cart that they are to pull."),
        Word("Yonder", "At some distance in the direction indicated; over there."),
        // Z
        Word("Zealot", "A person who is fanatical and uncompromising in pursuit of their religious, political, or other ideals."),
        Word("Zenith", "The time at which something is most powerful or successful."),
        Word("Zephyr", "A soft gentle breeze."),
        Word("Zest", "Great enthusiasm and energy.")
    };
    return dictionary;
}
