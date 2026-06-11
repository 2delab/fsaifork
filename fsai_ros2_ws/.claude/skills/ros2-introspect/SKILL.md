---
name: ros2-introspect
description: Use this skill whenever the user asks about ROS2 system introspection — listing nodes, topics, services, actions, or parameters; inspecting what's being published or subscribed; checking node connectivity; understanding the ROS2 graph; or debugging ROS2 communication. Always use this skill for any ROS2 CLI introspection queries — it parses raw output into clear, actionable summaries.
compatibility:
  - Required: ROS2 installation with CLI tools available
---

# ROS2 System Introspection Skill

Use this skill to explore and understand a running ROS2 system. Instead of showing raw CLI output, it structures results into readable summaries with key insights.

## Core Commands

The skill should use these ROS2 CLI tools:

- `ros2 node list` — List all active nodes
- `ros2 node info <node-name>` — Inspect a specific node (publications, subscriptions, services, actions)
- `ros2 topic list` — List all topics
- `ros2 topic info <topic-name>` — Topic details (message type, publishers, subscribers, history policy)
- `ros2 topic echo <topic-name> --once` — Sample a single message from a topic
- `ros2 service list` — List all services
- `ros2 service type <service-name>` — Get service message type
- `ros2 action list` — List all actions
- `ros2 param list` — List all parameters
- `ros2 param get <node-name> <param-name>` — Get a specific parameter value

## Introspection Workflow

When the user asks for ROS2 introspection:

1. **Check ROS2 availability**: Run `ros2 node list` first. If it fails, report that ROS2 is not available or not running, and ask the user to ensure a ROS2 system is active.

2. **Gather data**: Execute the appropriate CLI commands based on what the user is asking about. Run multiple commands as needed to build a complete picture.

3. **Parse and structure**: Don't dump raw output. Instead:
   - Extract meaningful data (node names, topic names, message types, etc.)
   - Show relationships (which nodes publish/subscribe to which topics)
   - Highlight important details (message rates, queue sizes, QoS settings if visible)
   - Flag any issues (nodes with no publishers/subscribers, disconnected components)

4. **Summarize**: Present results in this order:
   - **Overview**: High-level summary (e.g., "X nodes, Y topics, Z services active")
   - **Details**: Organized by category (nodes, topics, services, etc.)
   - **Insights**: Connections, patterns, or potential issues (e.g., "Node A publishes to 5 topics but no subscribers", "Topic `/control` has 3 publishers — potential conflict")

## Output Format

Use this structure for clarity:

```
## ROS2 System Overview
- Active Nodes: N
- Topics: M
- Services: K
- Parameters: P

## Nodes
- node_name: [subscriptions] → [publications] → [services] → [actions]
  
## Topics
- topic_name (message_type)
  Publishers: [node1, node2, ...]
  Subscribers: [node3, node4, ...]
  
## Services
- service_name (service_type)
  Server: node_name
  
## Actions
- action_name (action_type)
  Server: node_name

## Key Insights
- [Notable connections, issues, or patterns]
```

## Common Use Cases

**"Show me the full ROS2 graph"**
- List all nodes
- List all topics with their publishers/subscribers
- Show the connectivity between nodes

**"What is node X doing?"**
- Get node info: subscriptions, publications, services, actions
- List the topics it touches
- Show what other nodes it's connected to

**"Inspect topic Y"**
- Get topic type and details
- List all publishers and subscribers
- Sample a message if relevant
- Show QoS or rate information

**"Find disconnected components"**
- List all nodes and topics
- Identify any topics with publishers but no subscribers (or vice versa)
- Flag potential issues

## Error Handling

- If ROS2 is not available or running, clearly report this and ask the user to start a ROS2 system.
- If a specific node/topic/service doesn't exist, report it and suggest alternatives (e.g., "Did you mean...?").
- If commands timeout or fail, explain the error and suggest debugging steps.

## Tips

- Use `--include-hidden-nodes` with node/topic list commands if needed to see system nodes.
- When sampling topic messages with `ros2 topic echo`, use `--once` to get just one message.
- For large systems, start with high-level overviews, then drill into specifics.
- Parse QoS, history, and message rates from topic/node info output when present.
