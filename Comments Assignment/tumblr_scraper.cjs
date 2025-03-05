const readline = require('readline');
async function fetchModule() {
    return (await import('node-fetch')).default;
}

class BloggerScraper {
    constructor(blogName) {
        this.blogName = blogName;
        this.apiUrl = `https://${blogName}.blogspot.com/feeds/posts/default?alt=json`;
    }

    async fetchData() {
        const fetch = await fetchModule();
        const response = await fetch(this.apiUrl);
        if (!response.ok) {
            throw new Error(`Failed to fetch data: ${response.statusText}`);
        }
        return response.json();
    }
}

class BloggerDataProcessor {
    constructor(blogData) {
        this.blogData = blogData;
    }

    extractBasicInfo() {
        const feed = this.blogData.feed;
        return {
            title: feed.title?.$t || "No title",
            description: feed.subtitle?.$t || "No description",
            name: feed.author?.[0]?.name?.$t || "Unknown",
            totalPosts: feed.entry?.length || 0
        };
    }

    extractAllImages() {
        const posts = this.blogData.feed.entry || [];
        let imageUrls = [];

        posts.forEach((post) => {
            const content = post.content?.$t || "";

            // Extract image URLs using regex
            const images = [...content.matchAll(/<img.*?src=["'](.*?)["']/g)].map(match => match[1]);

            if (images.length > 0) {
                imageUrls.push(...images); // Flatten images into one array
            }
        });

        return imageUrls;
    }
}

class BloggerOutputFormatter {
    static printData(basicInfo, imageUrls) {
        console.log(`\nTitle: ${basicInfo.title}`);
        console.log(`Name: ${basicInfo.name}`);
        console.log(`Description: ${basicInfo.description}`);
        console.log(`No of posts: ${basicInfo.totalPosts}\n`);

        imageUrls.forEach((url, index) => {
            console.log(`${index + 1}. ${url}`);
        });
    }
}

class BloggerUserInput {
    static getUserInput(callback) {
        const rl = readline.createInterface({
            input: process.stdin,
            output: process.stdout
        });

        rl.question("Enter the Blogger blog name (e.g., 'dummyqwert'): ", (blogName) => {
            callback(blogName);
            rl.close();
        });
    }
}

async function main(blogName) {
    try {
        const scraper = new BloggerScraper(blogName);
        const blogData = await scraper.fetchData();

        const processor = new BloggerDataProcessor(blogData);
        const basicInfo = processor.extractBasicInfo();
        const imageUrls = processor.extractAllImages();

        BloggerOutputFormatter.printData(basicInfo, imageUrls);
    } catch (error) {
        console.error("Error:", error.message);
    }
}

BloggerUserInput.getUserInput(main);
